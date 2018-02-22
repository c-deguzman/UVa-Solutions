#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>

using namespace std;

const int maxn = 105;

int n;

int disc_time;
bool vis[maxn], ap[maxn];
int disc[maxn], low[maxn], parent[maxn];

vector <int> adj[maxn];

bool init(){
    cin >> n;

    if (n == 0) return false;

    disc_time = 0;

    for (int i=1; i <= n; i++){
        adj[i].clear();
        ap[i] = vis[i] = false;
        parent[i] = disc[i] = low[i] = -1;
    }

    string inp_line;

    while (getline(cin, inp_line)){
        if (inp_line == "0"){
            break;
        }

        stringstream ss(inp_line);

        int to, from;
        ss >> to;

        while (ss >> from){
            adj[to].push_back(from);
            adj[from].push_back(to);
        }
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

            if (parent[node] == -1){
                if (children > 1){
                    ap[node] = true;
                }
            } else if (low[next] >= disc[node]){
                ap[node] = true;
            }

        } else if (parent[node] != next){
            low[node] = min(low[node], disc[next]);
        }
    }
}

int solve(){
    int total = 0;

    for (int i=1; i <= n; i++){
        if (!vis[i]){
            ap_solve(i);
        }

        if (ap[i]){
            total++;
        }
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (init()){
        cout << solve() << endl;
    }
}
