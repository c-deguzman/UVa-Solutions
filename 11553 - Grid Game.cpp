#include <iostream>
#include <cstdio>

using namespace std;

int t;

const int INF = 1e9;

int ans[1 << 8][1 << 8][8][2];
int n;

int base[9][9];

void init(){
    for (int i=0; i < (1 << n); i++){
        for (int j=0; j < (1 << n); j++){
            for (int k = 0; k < n; k++){
                ans[i][j][k][0] = ans[i][j][k][1] = INF;
            }
        }
    }
}

int solve(int bitmask_a, int bitmask_b, int a_select, bool turn_a){
    if (bitmask_a == (1 << n) - 1 && bitmask_b == (1 << n) - 1){
        return 0;
    }

    if (ans[bitmask_a][bitmask_b][a_select][turn_a] != INF){
        return ans[bitmask_a][bitmask_b][a_select][turn_a];
    }

    int best;

    if (turn_a){
        best = INF * -1;

        for (int i=0; i < n; i++){
            if (!(bitmask_a & (1 << i))){
                best = max(best, solve(bitmask_a | (1 << i), bitmask_b, i, false));
            }
        }

    } else {
        best = INF;

        for (int i=0; i < n; i++){
            if (!(bitmask_b & (1 << i))){
                best = min(best, solve(bitmask_a, bitmask_b | (1 << i), 0, true) + base[a_select][i]);
            }
        }
    }

    return ans[bitmask_a][bitmask_b][a_select][turn_a] = best;

}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){
        scanf(" %d", &n);

        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                scanf(" %d", &base[i][j]);
            }
        }

        init();

        printf("%d\n", solve(0, 0, 0, true));

    }
}
