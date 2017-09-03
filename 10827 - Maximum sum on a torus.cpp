#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 78;

int tc, n;
int arr[maxn][maxn];
int sum[maxn * 2][maxn * 2];

void init(void){
    scanf(" %d", &n);

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            scanf(" %d", &arr[i][j]);
        }
    }

    for (int i=0; i < n * 2; i++){
        for (int j=0; j < n * 2; j++){
            int real_i = i;
            int real_j = j;

            if (real_i >= n){
                real_i -= n;
            }

            if (real_j >= n){
                real_j -= n;
            }

            sum[i][j] = arr[real_i][real_j];

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
    int base = sum[c][d];

    if (a){
        base -= sum[a - 1][d];
    }

    if (b){
        base -= sum[c][b - 1];
    }

    if (a && b){
        base += sum[a - 1][b - 1];
    }

    return base;
}

void solve(void){
    int best = arr[0][0];

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            for (int k=i; k < i + n; k++){
                for (int l=j; l < j + n; l++){
                    best = max(best, select(i, j, k, l));
                }
            }
        }
    }

    printf("%d\n", best);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){
        init();
        solve();
    }

}
