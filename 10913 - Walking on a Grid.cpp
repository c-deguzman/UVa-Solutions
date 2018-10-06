#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 75 + 2;
const int maxk = 5 + 2;
const int dir = 3 + 2;

int n, k, case_num;
int dp[maxn][maxn][maxk][dir], grid[maxn][maxn];

void reset(){
    for (int i=0; i < maxn; i++){
        for (int m = 0; m < maxn; m++){
            for (int j=0; j < maxk; j++){
                for (int l = 0; l < dir; l++){
                    dp[i][m][j][l] = -1e9;
                }
            }
        }
    }
}

bool input(){
    scanf(" %d %d", &n, &k);

    if (n == 0 && k == 0) return false;

    case_num++;

    for (int i=1; i <= n; i++){
        for (int j=1; j <= n; j++){
            scanf(" %d", &grid[i][j]);
        }
    }

    return true;
}

int solve(int curr_y, int curr_x, int curr_neg, int curr_dir){
    if (dp[curr_y][curr_x][curr_neg][curr_dir] != -1e9){
        return dp[curr_y][curr_x][curr_neg][curr_dir];
    }

    if (curr_neg > k) return -1e9;

    if (curr_y == n && curr_x == n){
        return grid[n][n];
    }

    int best = -1e9;

    if (curr_y < n){
        bool next_neg = (grid[curr_y + 1][curr_x] < 0);
        best = max(best, solve(curr_y + 1, curr_x, curr_neg + next_neg, 0));
    }

    if (curr_x > 1 && (curr_dir == 0 || curr_dir == 1)){
        bool next_neg = (grid[curr_y][curr_x - 1] < 0);
        best = max(best, solve(curr_y, curr_x - 1, curr_neg + next_neg, 1));
    }

    if (curr_x < n && (curr_dir == 0 || curr_dir == 2)){
        bool next_neg = (grid[curr_y][curr_x + 1] < 0);
        best = max(best, solve(curr_y, curr_x + 1, curr_neg + next_neg, 2));
    }

    return dp[curr_y][curr_x][curr_neg][curr_dir] = + grid[curr_y][curr_x] + best;

}

int main()
{
    ios:: sync_with_stdio(false);

    while (input()){
        reset();
        int ans = solve(1, 1, (grid[1][1] < 0), 0);

        printf("Case %d: ", case_num);
        if (ans < -1e8){
            printf("impossible\n");
        } else {
            printf("%d\n", ans);
        }
    }
}
