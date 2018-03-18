#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e4 + 7;

int n, m, s, t, p;
vector < pair <int, int> > adj1[maxn], adj2[maxn];
vector < pair < int, pair <int, int> > > edge_list;
int dist1[maxn], dist2[maxn];

void init(){
    scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);

    for (int i=0; i <= n; i++){
        adj1[i].clear();
        adj2[i].clear();
        dist1[i] = dist2[i] = 1e9;
    }

    edge_list.clear();

    for (int i=0; i < m; i++){
        int u, v, c;
        scanf("%d %d %d", &u, &v, &c);
        adj1[u].push_back({v, c});
        adj2[v].push_back({u, c});
        edge_list.push_back({c * -1, {u, v}});
    }

    sort(edge_list.begin(), edge_list.end());
}

void dijkstra(int start_node, int dist[], vector < pair <int, int> > adj[]){
    priority_queue < pair <int, int> > pq;
    pq.push({0, start_node});
    dist[start_node] = 0;

    while (!pq.empty()){
        pair <int, int> curr = pq.top();
        pq.pop();

        int cost = curr.first * -1;
        int node = curr.second;

        if (dist[node] < cost) continue;

        for (int i=0; i < adj[node].size(); i++){
            int next_node = adj[node][i].first;
            int edge_cost = adj[node][i].second;

            if (dist[next_node] > edge_cost + cost){
                dist[next_node] = edge_cost + cost;
                pq.push({dist[next_node] * -1, next_node});
            }
        }
    }
}

void solve(){
    for (int i=0; i < edge_list.size(); i++){
        int weight = edge_list[i].first * -1;
        int u = edge_list[i].second.first;
        int v = edge_list[i].second.second;

        if (dist1[u] + weight + dist2[v] <= p){
            printf("%d\n", weight);
            return;
        }
    }

    printf("%d\n", -1);
}


int main()
{
    ios::sync_with_stdio(false);

    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--){
        init();
        dijkstra(s, dist1, adj1);
        dijkstra(t, dist2, adj2);
        solve();
    }
}
