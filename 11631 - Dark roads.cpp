#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 200000 + 7;

int n, m, total_cost;

int u_parent[maxn], u_rank[maxn];
vector < pair < int, pair <int, int> > > edge_list;

bool init(){
    scanf("%d %d", &n, &m);

    if (n == 0 && m == 0){
        return false;
    }

    total_cost = 0;
    edge_list.clear();

    for (int i=0; i < m; i++){
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);
        edge_list.push_back({cost, {a, b}});

        total_cost += cost;

        u_rank[i] = 0;
        u_parent[i] = i;
    }

    sort(edge_list.begin(), edge_list.end());

    return true;
}

int parent_of(int node){
    if (u_parent[node] == node){
        return node;
    }

    return u_parent[node] = parent_of(u_parent[node]);
}

bool join(int a, int b){
    int parent_a = parent_of(a);
    int parent_b = parent_of(b);

    if (parent_a == parent_b){
        return false;
    }

    if (u_rank[parent_a] > u_rank[parent_b]){
        u_parent[parent_b] = parent_a;
    } else {
        u_parent[parent_a] = parent_b;

        if (u_rank[parent_a] == u_rank[parent_b]){
            u_rank[parent_b]++;
        }
    }

    return true;
}

int kruskals(){
    int mst_cost = 0, edges = 0;

    for (int i=0; i < edge_list.size(); i++){
        int a = edge_list[i].second.first;
        int b = edge_list[i].second.second;
        int weight = edge_list[i].first;

        if (join(a, b)){
            mst_cost += weight;
            edges++;

            // We have a tree
            if (edges == n - 1){
                break;
            }
        }
    }

    return mst_cost;
}

void solve(){
    printf("%d\n", total_cost - kruskals());
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }

}
