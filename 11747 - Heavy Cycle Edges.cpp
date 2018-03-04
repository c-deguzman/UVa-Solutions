#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1005;

int n, m;
int u_parent[maxn], u_rank[maxn];
priority_queue < pair < int , pair < int, int > > > edge_list;

bool init(){
    scanf("%d %d", &n, &m);

    if (n == 0 && m == 0){
        return false;
    }

    for (int i=0; i < n; i++){
        u_parent[i] = i;
        u_rank[i] = 0;
    }

    for (int i=0; i < m; i++){
        int a, b, w;
        scanf("%d %d %d", &a, &b, &w);
        edge_list.push({w * -1, {a ,b}});
    }

    return true;
}

int parent_of(int node){
    if (u_parent[node] == node){
        return node;
    }
    return u_parent[node] = parent_of(u_parent[node]);
}

bool join(int a, int b){
    int p_a = parent_of(a);
    int p_b = parent_of(b);

    if (p_a != p_b){
        if (u_rank[p_a] > u_rank[p_b]){
            u_parent[p_b] = p_a;
        } else {
            u_parent[p_a] = p_b;

            if (u_rank[p_a] == u_rank[p_b]){
                u_rank[p_b]++;
            }
        }
    }

    return p_a != p_b;
}

void kruskals()
{
    queue <int> non_selected;

    while (!edge_list.empty()){
        pair < int, pair < int, int > > node = edge_list.top();
        edge_list.pop();

        int a = node.second.first;
        int b = node.second.second;
        int weight = node.first * -1;

        if (!join(a, b)){
            non_selected.push(weight);
        }
    }

    if (non_selected.empty()){
        printf("forest\n");
    } else {
        while (!non_selected.empty()){
            int curr = non_selected.front();
            non_selected.pop();

            if (non_selected.empty()){
                printf("%d\n", curr);
            } else {
                printf("%d ", curr);
            }
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        kruskals();
    }
}
