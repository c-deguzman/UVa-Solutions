#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1000 + 7;

int n, m;
vector < pair <int, int> > adj[maxn];
int dist[maxn], queued[maxn];
bool in_queue[maxn];

void init(){
    scanf("%d %d", &n, &m);

    for (int i=0; i < n; i++){
        dist[i] = 1e9;
        adj[i].clear();
        in_queue[i] = false;
        queued[i] = 0;
    }

    for (int i=0; i < m; i++){
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);

        adj[x].push_back({y, z});
    }
}

bool spfa(){
    queue <int> q;
    q.push(0);
    dist[0] = 0;
    queued[0]++;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        in_queue[curr] = false;

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i].first;
            int weight = adj[curr][i].second;

            if (dist[next] > dist[curr] + weight){
                dist[next] = dist[curr] + weight;
                q.push(next);
                in_queue[next] = true;
                queued[next]++;

                if (queued[next] >= n){
                    return true;
                }
            }
        }
    }

    return false;
}

void solve(){
    printf("%s\n", spfa() ? "possible" : "not possible");
}


int main()
{
    ios::sync_with_stdio(false);

    int test_cases;
    scanf("%d", &test_cases);
    while (test_cases--){
        init();
        solve();
    }
}
