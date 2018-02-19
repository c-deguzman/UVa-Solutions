#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;

int n, m;
vector <int> adj[maxn];

int in[maxn];

bool init(){
    scanf(" %d %d", &n, &m);

    if (n == 0 && m == 0){
        return false;
    }

    for (int i=0; i <= n; i++){
        in[i] = 0;
        adj[i].clear();
    }

    while (m--){
        int inp_to, inp_from;
        scanf(" %d %d", &inp_to, &inp_from);

        adj[inp_to].push_back(inp_from);
        in[inp_from]++;
    }

    return true;
}

void solve(){
    queue <int> q, sol;

    for (int i=1; i <= n; i++){
        if (!in[i]){
            q.push(i);
            sol.push(i);
        }
    }

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i];

            in[next]--;

            if (!in[next]){
                q.push(next);
                sol.push(next);
            }
        }
    }



    while (!sol.empty()){
        printf("%d", sol.front());
        sol.pop();
        printf(sol.empty() ? "\n" : " ");
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }

}
