#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 100 + 7;

struct Edge {
    int flow, cap, mirror;
};

int n, m, s, t, total_flow;
vector < pair <int, int> > res_flow[maxn];
vector < Edge > edge_list;
int init_dist[maxn];

bool setup(){
    scanf("%d", &n);

    if (n == 0) return false;

    total_flow = 0;

    for (int i=1; i <= n; i++){
        res_flow[i].clear();
    }
    edge_list.clear();

    scanf("%d %d %d", &s, &t, &m);

    for (int i=0; i < m; i++){
        int a, b, f;
        scanf("%d %d %d", &a, &b, &f);

        int a_to_b_id = edge_list.size();
        int b_to_a_id = edge_list.size() + 1;

        edge_list.push_back({0, f, b_to_a_id});
        edge_list.push_back({0, f, a_to_b_id});

        res_flow[a].push_back({b, a_to_b_id});
        res_flow[b].push_back({a, b_to_a_id});
    }

    return true;
}

void augment_path(vector < pair <int, int> > & p, int val){
    int curr = t;
    while (p[curr].first != -2){

        int edge_id = p[curr].second;
        int back_id = edge_list[edge_id].mirror;

        edge_list[edge_id].flow += val;
        edge_list[back_id].cap -=  val;

        curr = p[curr].first;
    }

    total_flow += val;
}

void edmonds_karp(){
    bool change = true;

    while (change){
        change = false;

        vector < pair <int, int> > p(maxn, {-1, -1});
        vector <int> low(maxn, 1e9);

        queue <int> q;
        q.push(s);
        p[s] = {-2, -2};

        while (!q.empty()){
            int curr = q.front();
            q.pop();
            if (curr == t) {
                change = true;
                augment_path(p, low[curr]);
                break;
            }

            for (int i=0; i < res_flow[curr].size(); i++){
                int next = res_flow[curr][i].first;
                int edge_id = res_flow[curr][i].second;

                Edge for_edge = edge_list[edge_id];
                Edge back_edge = edge_list[for_edge.mirror];


                int available_flow = (for_edge.cap - for_edge.flow) + back_edge.flow;

                if (available_flow > 0 && p[next].first == -1){
                    low[next] = min(low[curr], available_flow);
                    p[next] = {curr, back_edge.mirror};
                    q.push(next);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    for (int t=1; setup(); t++){
        edmonds_karp();
        printf("Network %d\nThe bandwidth is %d.\n\n", t, total_flow);
    }

}
