#include <iostream>
#include <cstdio>
#include <vector>
#include <bitset>
#include <queue>

using namespace std;

const int SOURCE = 1;

const int max_comp = 55;
const int inf = 1e9;

int m, w;
int res_cap[max_comp * 2][max_comp * 2];
vector < int > adj[max_comp * 2];

int in_id(int id){
    return id;
}

int out_id(int id){
    if (id == SOURCE || id == m) return id;
    return id + max_comp;
}

void reset(){
    for (int i=0; i < max_comp * 2; i++){
        for (int j=0; j < adj[i].size(); j++){
            int k = adj[i][j];
            res_cap[i][k] = 0;
        }
        adj[i].clear();
    }
}

bool input(){
    scanf(" %d %d", &m, &w);

    for (int i=0; i < m - 2; i++){
        int id, cost;
        scanf(" %d %d", &id, &cost);

        int in = in_id(id), out = out_id(id);

        adj[in].push_back(out);
        adj[out].push_back(in);

        res_cap[in][out] = cost;
        res_cap[out][in] = 0;
    }

    for (int i=0; i < w; i++){
        int id_a, id_b, cost;
        scanf(" %d %d %d", &id_a, &id_b, &cost);

        int in_a = in_id(id_a), out_a = out_id(id_a);
        int in_b = in_id(id_b), out_b = out_id(id_b);

        adj[out_a].push_back(in_b);
        adj[out_b].push_back(in_a);

        adj[in_b].push_back(out_a);
        adj[in_a].push_back(out_b);

        res_cap[out_a][in_b] = cost;
        res_cap[out_b][in_a] = cost;
    }

    return (m || w);
}

void augment_path(vector <int> & parent, int node, int & min_flow){

    if (node == SOURCE) return;

    min_flow = min(min_flow, res_cap[parent[node]][node]);
    augment_path(parent, parent[node], min_flow);

    res_cap[parent[node]][node] -= min_flow;
    res_cap[node][parent[node]] += min_flow;

}

void solve(){

    bool found_path = true;

    vector <int> parent (max_comp * 2);
    int max_flow = 0;

    while (found_path){
        found_path = false;

        bitset < max_comp * 2 > vis;
        queue <int> q;

        q.push(SOURCE);
        vis[SOURCE] = true;

        while (!q.empty()){

            int curr = q.front();
            q.pop();

            if (curr == m){
                found_path = true;
                break;
            }

            for (int i=0; i < adj[curr].size(); i++){
                int next = adj[curr][i];

                if (!vis[next] && res_cap[curr][next] > 0){
                    vis[next] = true;
                    parent[next] = curr;
                    q.push(next);
                }
            }
        }

        if (found_path){
            int flow_aug = inf;
            augment_path(parent, m, flow_aug);

            max_flow += flow_aug;
        }
    }

    printf("%d\n", max_flow);
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        solve();
        reset();
    }

}
