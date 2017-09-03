#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
int sum[maxn][maxn];
int n;


void init(void){
    scanf(" %d", &n);

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            scanf(" %d", &sum[i][j]);

            if (i){
                sum[i][j] += sum[i - 1][j];
            }

            if (j){
                sum[i][j] += sum[i][j - 1];
            }

            if (i && j){
                sum[i][j] -= sum[i - 1][j - 1];
            }
        }
    }
}

int select(int a, int b, int c, int d){
    int total = sum[c][d];

    if (a){
        total -= sum[a - 1][d];
    }

    if (b){
        total -= sum[c][b - 1];
    }

    if (a && b){
        total += sum[a - 1][b - 1];
    }

    return total;
}

int solve(void){

    int best = -128;

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            for (int k=i; k < n; k++){
                for (int l=j; l < n; l++){
                    best = max(best, select(i, j, k, l));
                }
            }
        }
    }

    return best;
}

int main()
{
    ios::sync_with_stdio(false);

    init();
    printf("%d\n", solve());
}
