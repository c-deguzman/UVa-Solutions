#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
const int mod = 1e6 + 7;
int n, test_cases;

int paths[maxn][maxn];
char board[maxn][maxn];
pair <int, int> w_loc;

void input(){
    scanf(" %d", &n);

    for (int i=0; i < n; i++){
        scanf(" %s", &board[i]);
        for (int j=0; j < n; j++){
            if (board[i][j] == 'W'){
                w_loc = {i, j};
            }
            paths[i][j] = -1;
        }
    }

}

int solve(int y, int x){
    if (paths[y][x] != -1){
        return paths[y][x];
    }

    if (y == 0){
        return 1;
    }

    int total = 0;

    if (x + 1 < n && y - 1 >= 0){
        if (board[y - 1][x + 1] == '.'){
            total += solve(y - 1, x + 1);
        } else if (x + 2 < n && y - 2 >= 0 &&
                    board[y - 2][x + 2] == '.'){

            total += solve(y - 2, x + 2);
        }
    }

    total %= mod;

    if (x - 1 >= 0 && y - 1 >= 0){
        if (board[y - 1][x - 1] == '.'){
            total += solve(y - 1, x - 1);
        } else if (x - 2 >= 0 && y - 2 >= 0 &&
                    board[y - 2][x - 2] == '.'){

            total += solve(y - 2, x - 2);
        }
    }

    total %= mod;

    return paths[y][x] = total;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &test_cases);

    for (int c = 1; c <= test_cases; c++){
        input();
        printf("Case %d: %d\n", c, solve(w_loc.first, w_loc.second));
    }
}
