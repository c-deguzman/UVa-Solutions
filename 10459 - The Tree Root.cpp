#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int maxn = 5000 + 3;
const int inf = 1e9;

int n;
int dist[maxn];
vector <int> adj[maxn];

void reset(){
    for (int i=0; i < n; i++){
        adj[i].clear();
    }
}


bool input(){
    int valid = scanf(" %d", &n);

    if (valid != 1) return false;

    reset();

    for (int i=0; i < n; i++){
        int m;
        scanf(" %d", &m);
        for (int j=0; j < m; j++){
            int child;
            scanf(" %d", &child);
            adj[i].push_back(child - 1);
        }
    }

    return true;
}

void dist_reset(){
    for (int i=0; i < n; i++){
        dist[i] = inf;
    }
}

vector <int> bfs_max(int start){
    dist_reset();

    vector <int> res;

    int max_dist = 0;
    int farthest_node = -1;

    queue <int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        if (max_dist < dist[curr]){
            max_dist = dist[curr];
            res.clear();
            res.push_back(curr);
        } else if (max_dist == dist[curr]){
            res.push_back(curr);
        }

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i];

            if (dist[next] == inf){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    return res;
}

vector <int> solve_near_set(int max_dist){
    vector <int> res;
    for (int i=0; i < n; i++){
        if (dist[i] == max_dist / 2){
            res.push_back(i);
        } else if (dist[i] == max_dist / 2 + 1 && (max_dist % 2)){
            res.push_back(i);
        }
    }

    return res;
}

void solve(){
    vector <int> low, high;
    int low_h = inf, high_h = -1;


    vector <int> far_set_one = bfs_max(0);
    vector <int> far_set_two = bfs_max(far_set_one[0]);

    vector <int> near_set_one = solve_near_set(dist[far_set_two[0]]);
    bfs_max(far_set_two[0]);
    vector <int> near_set_two = solve_near_set(dist[far_set_one[0]]);


    sort(far_set_one.begin(), far_set_one.end());
    sort(far_set_two.begin(), far_set_two.end());
    sort(near_set_one.begin(), near_set_one.end());
    sort(near_set_two.begin(), near_set_two.end());

    printf("Best Roots  :");
    int pi = 0, pj = 0;
    while (pi < near_set_one.size() || pj < near_set_two.size()){
        int next;
        if (pi == near_set_one.size()){
            break;
        } else if (pj == near_set_two.size()){
            break;
        } else if (near_set_one[pi] == near_set_two[pj]){
            next = near_set_one[pi++];
            pj++;
        } else if (near_set_one[pi] < near_set_two[pj]){
            pi++;
        } else if (near_set_one[pi] > near_set_two[pj]){
            pj++;
        }

        if (next != -1){
            printf(" %d", next + 1);
            next = -1;
        }
    }
    printf("\n");

    printf("Worst Roots :");
    pi = 0, pj = 0;
    while (pi < far_set_one.size() || pj < far_set_two.size()){
        int next;
        if (pi == far_set_one.size()){
            next = far_set_two[pj++];
        } else if (pj == far_set_two.size()){
            next = far_set_one[pi++];
        } else if (far_set_one[pi] <= far_set_two[pj]){
            if (far_set_one[pi] == far_set_two[pj]){
                pj++;
            }
            next = far_set_one[pi++];
        } else {
            next = far_set_two[pj++];
        }

        printf(" %d", next + 1);
    }
    printf("\n");

}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        solve();
    }

}
