#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>

using namespace std;

const int maxp = 505;

int s, p, tc;
int u_parent[maxp], u_rank[maxp];
pair <int, int> coords[maxp];
priority_queue < pair < double, pair < int, int > > > edge_list;

int parent_of(int node){
    if (u_parent[node] == node){
        return node;
    }
    return u_parent[node] = parent_of(u_parent[node]);
}

bool join(int a, int b){
    int p_a = parent_of(a);
    int p_b = parent_of(b);

    if (p_a != p_b){
        if (u_rank[p_a] > u_rank[p_b]){
            u_parent[p_b] = p_a;
        } else {
            u_parent[p_a] = p_b;

            if (u_rank[p_a] == u_rank[p_b]){
                u_rank[p_b]++;
            }
        }
    }

    return p_a != p_b;
}

void add_edge(int a, int b){
    int delta_x = coords[a].first - coords[b].first;
    int delta_y = coords[a].second - coords[b].second;

    int sq_dist = delta_x * delta_x + delta_y * delta_y;
    double dist = sqrt((double) sq_dist);

    edge_list.push({dist * -1, {a, b}});
}

void init(){
    scanf("%d %d", &s, &p);

    for (int i=0; i < p; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        coords[i] = {x, y};
        u_parent[i] = i;
        u_rank[i] = 0;
    }

    for (int i=0; i < p; i++){
        for (int j=0; j < p; j++){
            if (i == j){
                continue;
            }

            add_edge(i, j);
        }
    }
}

void kruskals(){
    int trees = p;

    double max_cost = 0;

    while (!edge_list.empty() && trees > s){
        pair < double , pair < int, int > > top = edge_list.top();
        edge_list.pop();

        double cost = top.first * -1;
        int a = top.second.first;
        int b = top.second.second;

        if (join(a, b)){
            trees--;
            max_cost = max(max_cost, cost);
        }
    }

    printf("%.2f\n", max_cost);
}


int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &tc);

    while (tc--){
        init();
        kruskals();
    }
}
