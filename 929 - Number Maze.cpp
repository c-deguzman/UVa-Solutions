#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1e3 + 7;

int n, m;
int grid[maxn][maxn], dist[maxn][maxn];

void init(){
    scanf("%d %d", &n, &m);

    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            scanf("%d", &grid[i][j]);
            dist[i][j] = 1e9;
        }
    }
}

void solve(){
    priority_queue < pair <int, int> > pq;
    pq.push({0, 0});
    dist[0][0] = 0;

    while (!pq.empty()){
        pair <int, int> top = pq.top();
        pq.pop();

        int weight = top.first * -1;
        int r = top.second / m;
        int c = top.second % m;

        if (dist[r][c] < weight) continue;

        if (r == n - 1 && c == m - 1){
            printf("%d\n", weight + grid[n - 1][m - 1]);
            return;
        }

        for (int i=-1; i <= 1; i++){
            for (int j=-1; j <= 1; j++){
                if ((i && j) || !(i || j)) continue;

                if ((0 <= (r + i) && (r + i) < n) &&
                    (0 <= (c + j) && (c + j) < m) &&
                    (dist[r + i][c + j] > weight + grid[r][c])){

                    int next_weight = dist[r + i][c + j] = weight + grid[r][c];
                    int next_ind = (r + i) * m + (c + j);

                    pq.push({next_weight * -1, next_ind});
                }
            }
        }
    }
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
