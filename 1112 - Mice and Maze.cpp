#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 107;

int n, e, t, m;
vector < pair <int, int> > adj[maxn];
int dist[maxn];

void init(){
    scanf("%d %d %d %d", &n, &e, &t, &m);

    for (int i=0; i <= n; i++){
        adj[i].clear();
        dist[i] = 1e9;
    }

    for (int i=0; i < m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        adj[b].push_back({a, w});
    }
}

void solve(){
    priority_queue < pair <int, int> > pq;
    pq.push({0, e});
    dist[e] = 0;

    while (!pq.empty()){
        pair <int, int> top = pq.top();
        pq.pop();

        int weight = top.first * -1;
        int node = top.second;

        if (dist[node] < weight) continue;

        for (int i=0; i < adj[node].size(); i++){
            int next_node = adj[node][i].first;
            int next_weight = adj[node][i].second;

            if (next_weight + dist[node] < dist[next_node]){
                dist[next_node] = next_weight + dist[node];
                pq.push({dist[next_node] * -1, next_node});
            }
        }
    }

    int total_surv = 0;
    for (int i=1; i <= n; i++){
        if (dist[i] <= t){
            total_surv++;
        }
    }

    printf("%d\n", total_surv);
}

int main()
{
    ios::sync_with_stdio(false);

    int num_cases;
    scanf("%d", &num_cases);
    while (num_cases--){
        init();
        solve();

        if (num_cases){
            printf("\n");
        }
    }
}
