#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxv = 207;

int v, e;
vector <int> adj[maxv];
int colour[maxv];

void init(){
    scanf("%d %d", &v, &e);

    for (int i=0; i < v; i++){
        adj[i].clear();
        colour[i] = 0;
    }

    for (int i=0; i < e; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int colour_valid(int node, int my_colour, int & total_nodes){
    colour[node] = my_colour;
    int next_colour = my_colour == 1 ? 2 : 1;
    int total_ones = my_colour == 1 ? 1 : 0;
    total_nodes++;

    for (int i=0; i < adj[node].size(); i++){
        int next_node = adj[node][i];

        if (!colour[next_node]){
            int res_ones = colour_valid(next_node, next_colour, total_nodes);
            if (res_ones == -1){
                return -1;
            }
            total_ones += res_ones;
        } else if (colour[next_node] == my_colour){
            return -1;
        }
    }

    return total_ones;
}

void solve(){
    int total_min = 0, total_nodes;

    for (int i=0; i < v; i++){
        if (!colour[i]){
            total_nodes = 0;
            int res_ones = colour_valid(i, 1, total_nodes);

            if (res_ones == -1){
                total_min = -1;
                break;
            }
            total_min += max(min(res_ones, total_nodes - res_ones), 1);
        }
    }

    printf("%d\n", total_min);
}

int main()
{
    ios::sync_with_stdio(false);

    int num_cases;
    scanf("%d", &num_cases);
    while (num_cases--){
        init();
        solve();
    }
}
