#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;

struct Edge {
    int weight, dest, id;

    bool operator<(const Edge & rhs) const {
        return weight > rhs.weight;
    }
};

int tc, n, m;
vector < Edge > adj[maxn];
bool vis[maxn];
vector < int > taken_id;

void init(){
    scanf("%d %d", &n, &m);

    for (int i=1; i <= n; i++){
        adj[i].clear();
        vis[i] = false;
    }

    taken_id.clear();

    for (int i=0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);

        adj[a].push_back({c, b, i});
        adj[b].push_back({c, a, i});
    }
}

void expand(int node, priority_queue<Edge> & pq, int avoid){
    vis[node] = true;

    for (int i=0; i < adj[node].size(); i++){
        Edge e = adj[node][i];

        if (!vis[e.dest] && (e.id != avoid)){
            pq.push(e);
        }
    }
}

int prims(int avoid){
    int total_cost = 0;
    priority_queue <Edge> pq;

    expand(1, pq, avoid);

    while (!pq.empty()){
        Edge e = pq.top();
        pq.pop();

        if (!vis[e.dest]){
            total_cost += e.weight;
            expand(e.dest, pq, avoid);

            if (avoid == -1){
                taken_id.push_back(e.id);
            }
        }
    }

    // Check if tree spans
    for (int i=1; i <= n; i++){
        if (!vis[i]){
            total_cost = 1e9;
        }
        vis[i] = false;
    }

    return total_cost;
}

void solve(){
    int best = prims(-1);
    int next_best = 1e9;

    for (int i=0; i < taken_id.size(); i++){
        int attempt = prims(taken_id[i]);

        next_best = min(next_best, attempt);
    }

    printf("%d %d\n", best, next_best);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &tc);

    while(tc--){
        init();
        solve();
    }
}
