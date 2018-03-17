#include <iostream>
#include <algorithm>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100, maxe = 5;
const int SWITCH_COST = 60;

int n, k;
vector <int> elv[maxe];
int dist[maxn], t[maxe];

struct State{
    int cost, cf, ce;
    State(int cost, int cf, int ce): cost{cost}, cf{cf}, ce{ce} {}
    bool operator<(const State & rhs) const {
        return cost > rhs.cost;
    }
};

void reset(){
    for (int i=0; i < maxn; i++){
        dist[i] = 1e9;
    }

    for (int i=0; i < maxe; i++){
        elv[i].clear();
    }
}

bool init(){
    if (!(cin >> n >> k)) return false;

    reset();

    for (int i=0; i < n; i++){
        cin >> t[i];
    }

    string full_line;
    int inp;

    for (int i=0; i < n; i++){
        do {
            getline(cin, full_line);
        } while (full_line.empty());

        stringstream ss(full_line);

        while (ss >> inp){
            elv[i].push_back(inp);
        }
    }

    return true;
}

void solve(){
    priority_queue < State > pq;
    dist[0] = 0;
    pq.push({0, 0, -1});

    while (!pq.empty()){
        State top = pq.top();
        pq.pop();

        int cost = top.cost;
        int curr_floor = top.cf;
        int curr_elv = top.ce;

        if (dist[curr_floor] < cost) continue;

        for (int i=0; i < n; i++){
            vector<int>::iterator it = lower_bound(elv[i].begin(), elv[i].end(), curr_floor);

            if (it == elv[i].end() || *it != curr_floor) continue;

            for (vector <int>::iterator next_it = elv[i].begin(); next_it != elv[i].end(); ++next_it){
                if (next_it == it) continue;

                int next_floor = *next_it;
                int edge_cost = abs(curr_floor - next_floor) * t[i];

                if (i != curr_elv && curr_elv != -1){
                    edge_cost += SWITCH_COST;
                }

                if (edge_cost + dist[curr_floor] < dist[next_floor]){
                    dist[next_floor] = edge_cost + dist[curr_floor];
                    pq.push({dist[next_floor], next_floor, i});
                }
            }
        }
    }

    if (dist[k] == 1e9){
        cout << "IMPOSSIBLE\n";
    } else {
        cout << dist[k] << "\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (init()){
        solve();
    }

}
