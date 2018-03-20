#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 200 + 7, START = 1;

int n, r, case_num;
vector <int> adj[maxn];
int busy[maxn], dist[maxn], queued[maxn];
bool in_queue[maxn];

bool init(){
    if (scanf("%d", &n) != 1) return false;

    case_num++;

    for (int i=1; i <= n; i++){
        scanf("%d", &busy[i]);
        dist[i] = 1e9;
        queued[i] = 0;
        in_queue[i] = false;
        adj[i].clear();
    }

    scanf("%d", &r);

    for (int i=0; i < r; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u].push_back(v);
    }

    return true;
}

void add_q(queue <int> & q, int node){
    q.push(node);
    queued[node]++;
    in_queue[node] = true;
}

int next_q(queue <int> & q){
    int node = q.front();
    q.pop();
    in_queue[node] = false;

    return node;
}

void spfa(){
    queue <int> q;
    dist[START] = 0;
    add_q(q, START);

    while (!q.empty()){
        int curr = next_q(q);

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i];
            int weight = (busy[next] - busy[curr]);
            weight = weight * weight * weight;

            if (dist[next] > dist[curr] + weight){
                if (queued[next] >= n) continue;

                dist[next] = dist[curr] + weight;
                add_q(q, next);
            }
        }
    }
}

void solve(){
    spfa();

    int q, inp;
    scanf("%d", &q);

    printf("Set #%d\n", case_num);
    while (q--){
        scanf("%d", &inp);

        if (queued[inp] >= n || dist[inp] < 3 || dist[inp] == 1e9){
            printf("?\n");
        } else {
            printf("%d\n", dist[inp]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
