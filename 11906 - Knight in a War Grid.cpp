#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 105;
int r,c,m,n;
int even, odd;

bool grid[maxn][maxn];
bool vis[maxn][maxn];

void init(){
    scanf("%d %d %d %d", &r, &c, &m, &n);

    even = odd = 0;

    for (int i=0; i < r; i++){
        for (int j=0; j < c; j++){
            vis[i][j] = false;
            grid[i][j] = false;
        }
    }

    int waters;

    scanf("%d", &waters);

    while (waters--){
        int wr, wc;
        scanf("%d %d", &wr, &wc);
        grid[wr][wc] = true;
    }
}

void bfs(){
    pair <int, int> start = make_pair(0,0);
    vis[0][0] = true;

    queue < pair <int, int> > q;

    q.push(start);

    while (!q.empty()){
        pair <int, int> curr = q.front();
        q.pop();

        int local_count = 0;

        for (int i=-1; i <= 1; i++){
            for (int j=-1; j <= 1; j++){
                if (i && j){
                    pair <int, int> opt_one = make_pair(i * m + curr.first, j * n + curr.second);
                    pair <int, int> opt_two = make_pair(i * n + curr.first, j * m + curr.second);

                    if ((0 <= opt_one.first  && opt_one.first < r) &&
                        (0 <=  opt_one.second && opt_one.second < c) &&
                        !grid[opt_one.first][opt_one.second]){

                        local_count++;

                        if (!vis[opt_one.first][opt_one.second]){
                            q.push(opt_one);
                            vis[opt_one.first][opt_one.second] = true;
                        }
                    }

                    if ((0 <= opt_two.first && opt_two.first < r) &&
                        (0 <= opt_two.second && opt_two.second < c)&&
                        !grid[opt_two.first][opt_two.second]){

                        local_count++;

                        if (!vis[opt_two.first][opt_two.second]){
                            q.push(opt_two);
                            vis[opt_two.first][opt_two.second] = true;
                        }
                    }
                }
            }
        }

        if (m == n || !m || !n ){
            local_count /= 2;
        }

        if (local_count % 2){
            odd++;
        } else {
            even++;
        }
    }
}

int main()
{
    int test_cases;

    scanf("%d", &test_cases);

    for (int i=1; i <= test_cases; i++){
        init();
        bfs();
        printf("Case %d: %d %d\n", i, even, odd);
    }
}
