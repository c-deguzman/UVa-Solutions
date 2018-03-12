#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 2507;

int n, cases;
vector <int> adj[maxn];

void init(){
    scanf("%d", &n);

    for (int i=0; i < n; i++){
        int edges;
        scanf("%d", &edges);

        for (int j=0; j < edges; j++){
            int edge;
            scanf("%d", &edge);
            adj[i].push_back(edge);
        }
    }
}

void query(int start){
    int dist[maxn] = {}, boom[maxn] = {};
    queue <int> q;

    q.push(start);

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i];

            if (!dist[next] && next != start){
                dist[next] = dist[curr] + 1;
                boom[dist[next]]++;
                q.push(next);
            }
        }
    }

    int best_size = 0, best_day = 0;

    for (int i=0; i < maxn; i++){
        if (boom[i] > best_size){
            best_size = boom[i];
            best_day = i;
        }
    }

    if (best_size){
        printf("%d %d\n", best_size, best_day);
    } else {
        printf("%d\n", best_size);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    init();
    scanf("%d", &cases);

    for (int i=0; i < cases; i++){
        int start_node;
        scanf("%d", &start_node);
        query(start_node);
    }
}
