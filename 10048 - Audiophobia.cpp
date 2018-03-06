#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxc = 105;

int c, s, q, test_case;

bool vis[maxc];
int u_parent[maxc], u_rank[maxc];
vector < pair <int, int> > adj[maxc];
priority_queue < pair < int, pair < int, int > > > edge_list;

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

bool init(){
    scanf("%d %d %d", &c, &s, &q);

    if (c == 0 && s == 0 && q == 0){
        return false;
    }

    if (test_case){
        printf("\n");
    }

    for (int i=0; i <= c; i++){
        u_parent[i] = i;
        u_rank[i] = 0;
        adj[i].clear();
    }

    for (int i=0; i < s; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edge_list.push({w * -1, {a, b}});
    }

    return true;
}

void kruskals(){
    while (!edge_list.empty()){
        pair < int, pair <int, int> > top = edge_list.top();
        edge_list.pop();

        int a = top.second.first;
        int b = top.second.second;

        int weight = top.first * -1;

        if (join(a, b)){
            adj[a].push_back({b, weight});
            adj[b].push_back({a, weight});
        }
    }
}

int path(int curr, int goal){
    vis[curr] = true;

    if (curr == goal){
        vis[curr] = false;
        return 0;
    }

    int low = -1;

    for (int i=0; i < adj[curr].size(); i++){
        int next = adj[curr][i].first;
        int weight = adj[curr][i].second;

        if (!vis[next]){
            low = max(low, path(next, goal));

            if (low >= 0){
                low = max(low, weight);
                break;
            }
        }
    }

    vis[curr] = false;
    return low;
}

void solve(){
    printf("Case #%d\n", ++test_case);
    for (int i=0; i < q; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        int low = path(a, b);

        if (low == -1){
            printf("no path\n");
        } else {
            printf("%d\n", low);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        kruskals();
        solve();
    }
}
