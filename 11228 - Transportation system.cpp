#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

const int maxn = 1000 + 7;

int test_cases, n, r;

bool taken[maxn];
pair <int, int> nodes[maxn];
priority_queue < pair <int, int> > attempt_list;

void init(){
    scanf("%d %d", &n, &r);

    for (int i=0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        nodes[i] = {x, y};
        taken[i] = false;
    }
}


void expand(int node){
    taken[node] = true;

    for (int i=0; i < n; i++){
        if (i != node && !taken[i]){
            int delta_x = (nodes[node].first - nodes[i].first);
            int delta_y = (nodes[node].second - nodes[i].second);

            int dist_sq = delta_x * delta_x + delta_y * delta_y;

            attempt_list.push({dist_sq * -1, i * -1});
        }
    }
}

void prims(int & states, int & road_cost, int & rail_cost){
    expand(0);

    int num_states = 1;
    double road_total = 0;
    double rail_total = 0;

    while (!attempt_list.empty()){
        pair <int, int> top_pair = attempt_list.top();
        attempt_list.pop();

        int next_node = top_pair.second * -1;
        int weight = top_pair.first * -1;

        if (taken[next_node]){
            continue;
        }

        if (weight > r * r){
            rail_total += sqrt((double) weight);
            num_states++;
        } else {
            road_total += sqrt((double) weight);
        }

        expand(next_node);
    }

    states = num_states;
    road_cost = round(road_total);
    rail_cost = round(rail_total);
}


void solve(int test_case){
    int states, road_cost, rail_cost;
    prims(states, road_cost, rail_cost);
    printf("Case #%d: %d %d %d\n", test_case, states, road_cost, rail_cost);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &test_cases);
    for (int i=1; i <= test_cases; i++){
        init();
        solve(i);
    }
}
