#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 10005;

int n, m, disc_time;

bool vis[maxn];
int p_pt[maxn], parent[maxn], disc[maxn], low[maxn];
vector <int> adj[maxn];

vector < pair <int, int> > soln;

void init(){
    for (int i=0; i < n; i++){
        vis[i] = false;
        p_pt[i] = 0;
        parent[i] = disc[i] = low[i] = -1;

        adj[i].clear();
    }

    soln.clear();
    disc_time = 0;
}

bool input(){
    scanf("%d %d", &n, &m);

    if (!n && !m){
        return false;
    }

    init();

    int inp_a, inp_b;

    while (scanf("%d %d", &inp_a, &inp_b)){
        if (inp_a == -1 & inp_b == -1){
            break;
        }

        adj[inp_a].push_back(inp_b);
        adj[inp_b].push_back(inp_a);
    }

    return true;
}

void ap_solve(int node){
    vis[node] = true;
    disc[node] = low[node] = disc_time++;

    int children = 0;

    for (int i=0; i < adj[node].size(); i++){
        int next = adj[node][i];

        if (!vis[next]){
            children++;
            parent[next] = node;
            ap_solve(next);

            low[node] = min(low[node], low[next]);


            if (parent[node] == -1 && children > 1){
                p_pt[node]++;
            } else if (parent[node] != -1  && disc[node] <= low[next]){
                p_pt[node]++;
            }

        } else if (parent[node] != next){
            low[node] = min(low[node], disc[next]);
        }
    }
}

void solve(){
    for (int i=0; i < n; i++){
        if (!vis[i]){
            ap_solve(i);
        }
        soln.push_back(make_pair(i, p_pt[i] + 1));
    }

    sort(soln.begin(), soln.end(),
         [](const pair<int, int> & a, const pair<int, int> &b) -> bool {
            if (a.second != b.second){
                return a.second > b.second;
            } else {
                return a.first < b.first;
            }
         });

    for (int i=0; i < m; i++){
        printf("%d %d\n", soln[i].first, soln[i].second);
    }
    printf("\n");
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        solve();
    }
}
