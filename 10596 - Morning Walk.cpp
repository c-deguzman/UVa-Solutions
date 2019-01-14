#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int maxn = 205;

int inter, roads;
vector <int> deg;
set <int> adj[maxn];

bool input(){


    if (scanf("%d %d", &inter, &roads) != 2) return false;

    deg.assign(inter, 0);

    for (int i=0; i < maxn; i++){
        adj[i].clear();
    }

    for (int i=0; i < roads; i++){
        int a, b;
        scanf("%d %d", &a, &b);

        deg[a]++;
        deg[b]++;

        adj[a].insert(b);
        adj[b].insert(a);
    }

    return true;
}

bool solve(){
    int start = -1;

    for (int i=0; i < inter; i++){
        if (deg[i] % 2) return false;

        if (!adj[i].empty()){
            start = i;
        }
    }

    if (start == -1) return false;

    vector <bool> vis(inter, false);
    queue <int> q;

    q.push(start);
    vis[start] = true;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (set<int>::iterator it = adj[curr].begin(); it != adj[curr].end(); it++){
            int next = *it;

            if (!vis[next]){
                vis[next] = true;
                q.push(next);
            }
        }
    }

    for (int i=0; i < inter; i++){
        if (!adj[i].empty() && !vis[i]) return false;
    }


    return true;
}



int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        printf(solve() ? "Possible\n" : "Not Possible\n");
    }

}
