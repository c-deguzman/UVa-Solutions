#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 105;
const int inf = 1e9;

int cases, r, c;
char name[maxn];
int dist[maxn][maxn], in[maxn][maxn], height[maxn][maxn];
vector < pair <int, int> > adj[maxn][maxn];

void reset(){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxn; j++){
            dist[i][j] = inf;
            adj[i][j].clear();
        }
    }
}

void input(){
    scanf(" %s %d %d", &name, &r, &c);

    for (int i=0; i < r; i++){
        for (int j=0; j < c; j++){
            scanf(" %d", &height[i][j]);
        }
    }
}

void top_preprocess(){
    for (int i=0; i < r; i++){
        for (int j=0; j < c; j++){

            for (int dr = -1; dr <= 1; dr++){
                for (int dc = -1; dc <= 1; dc++){
                    if ((0 <= i + dr && i + dr < r) &&
                        (0 <= j + dc && j + dc < c) &&
                        ((dr == 0) ^ (dc == 0))){

                        if (height[i + dr][j + dc] < height[i][j]){
                            adj[i][j].push_back({i + dr, j + dc});
                            in[i + dr][j + dc]++;
                        }


                    }
                }
            }


        }
    }
}


vector < pair <int, int> > top_sort(){
    top_preprocess();

    vector < pair <int, int> > ret;
    queue < pair <int, int> > q;

    for (int i=0; i < r; i++){
        for (int j=0; j < c; j++){
            if (!in[i][j]){
                dist[i][j] = -1;
                q.push({i, j});
                ret.push_back({i, j});
            }
        }
    }

    while (!q.empty()){
        pair <int, int> curr = q.front();
        q.pop();

        for (int i=0; i < adj[curr.first][curr.second].size(); i++){
            pair <int, int> next = adj[curr.first][curr.second][i];

            in[next.first][next.second]--;

            if (!in[next.first][next.second]){
                q.push(next);
                ret.push_back(next);
            }
        }
    }


    return ret;
}

int solve(){

    vector < pair <int, int> > top_order = top_sort();

    int best = 0;

    for (int i=0; i < top_order.size(); i++){
        pair <int, int> curr = top_order[i];

        best = min(best, dist[curr.first][curr.second]);

        for (int j=0; j < adj[curr.first][curr.second].size(); j++){
            pair <int,int> next = adj[curr.first][curr.second][j];

            dist[next.first][next.second] = min(dist[next.first][next.second], dist[curr.first][curr.second] - 1);
        }
    }

    return best * -1;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &cases);

    while (cases--){
        reset();
        input();
        printf("%s: %d\n", name, solve());
    }
}
