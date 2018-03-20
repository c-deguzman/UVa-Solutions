#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100 + 7, START = 1, START_ENERGY = 100;

int n;
vector <int> adj[maxn];
int energy[maxn], dist[maxn], queued[maxn];
bool in_queue[maxn];

bool init(){
    scanf("%d", &n);

    if (n == -1) return false;

    for (int i=1; i <= n; i++){
        dist[i] = -1e9;
        queued[i] = 0;
        in_queue[i] = false;
        adj[i].clear();

        scanf("%d", &energy[i]);

        int doors, door;
        scanf("%d", &doors);
        while (doors--){
            scanf("%d", &door);
            adj[i].push_back(door);
        }
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
    dist[START] = START_ENERGY;
    add_q(q, START);

    while (!q.empty()){
        int curr = next_q(q);

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i];
            int weight = energy[next];

            if (dist[curr] + weight <= 0) continue;

            if (dist[next] < dist[curr] + weight){
                if (queued[next] < n){
                    dist[next] = dist[curr] + weight;
                    add_q(q, next);
                } else if (queued[next] == n){
                    dist[next] = 1e9;
                    add_q(q, next);
                }
            }
        }
    }
}

void solve(){
    spfa();
    if (queued[n] >= n || dist[n] > 0){
        printf("winnable\n");
    } else {
        printf("hopeless\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
