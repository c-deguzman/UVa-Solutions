#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 5;
int n, disc_time;

vector <int> adj[maxn];
int parent[maxn], disc[maxn], low[maxn];
bool vis[maxn];

void init(){
    for (int i=0; i < n; i++){
        adj[i].clear();
        parent[i] = disc[i] = low[i] = -1;
        vis[i] = false;
    }
    disc_time = 0;
}

bool input(){
    if (!(cin >> n)){
        return false;
    }

    init();

    for (int i=0; i < n; i++){
        string full_line = "";

        while (full_line.size() < 3){
           getline(cin, full_line);
        }

        for (int j=0; j < full_line.size(); j++){
            if (full_line[j] == '(' || full_line[j] == ')'){
                full_line[j] = ' ';
            }
        }

        stringstream ss(full_line);

        int node, connects;
        ss >> node >> connects;

        for (int j=0; j < connects; j++){
            int next;
            ss >> next;

            adj[node].push_back(next);
        }
    }

    return true;
}


void bridge_solve(int node, vector < pair<int, int> > & soln){
    vis[node] = true;

    disc[node] = low[node] = disc_time++;

    int children = 0;

    for (int i=0; i < adj[node].size(); i++){
        int next = adj[node][i];

        if (!vis[next]){
            parent[next] = node;
            children++;

            bridge_solve(next, soln);

            low[node] = min(low[node], low[next]);

            if (disc[node] < low[next]){
                soln.push_back(make_pair(min(node, next), max(node, next)));
            }

        } else if (parent[node] != next){
            low[node] = min(low[node], disc[next]);
        }
    }
}

void solve() {
    vector < pair<int, int> > soln;

    for (int i=0; i < n; i++){
        if (!vis[i]){
            bridge_solve(i, soln);
        }
    }

    sort(soln.begin(), soln.end());

    cout << soln.size() << " critical links" << endl;

    for (int i=0; i < soln.size(); i++){
        cout << soln[i].first << " - " << soln[i].second << endl;
    }

    cout << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (input()){
        solve();
    }
}
