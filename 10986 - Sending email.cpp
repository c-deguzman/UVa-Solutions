#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2e4 + 7;

int n, m, s, t;
vector < pair <int, int> > adj[maxn];
int dist[maxn];

void init(){
    scanf("%d %d %d %d", &n, &m, &s, &t);

    for (int i=0; i < n; i++){
        dist[i] = 1e9;
        adj[i].clear();
    }

    for (int i=0; i < m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
}

void solve(){
    priority_queue < pair <int, int> > pq;
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()){
        pair <int, int> top = pq.top();
        pq.pop();

        int weight = top.first * -1;
        int node = top.second;

        if (dist[node] < weight) continue;

        for (int i=0; i < adj[node].size(); i++){
            int next_node = adj[node][i].first;
            int edge_weight = adj[node][i].second;

            if (edge_weight + dist[node] < dist[next_node]){
                dist[next_node] = edge_weight + dist[node];
                pq.push({dist[next_node] * -1, next_node});
            }
        }
    }

    if (dist[t] == 1e9){
        printf("unreachable\n");
    } else {
        printf("%d\n", dist[t]);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int num_cases;
    scanf("%d", &num_cases);

    for (int case_num = 1; case_num <= num_cases; case_num++){
        printf("Case #%d: ", case_num);
        init();
        solve();
    }
}
