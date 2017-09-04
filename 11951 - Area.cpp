#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;

int T, n, m;
long long sum[maxn][maxn];
long long sol_area, sol_cost, budget;

void init(void){
    scanf(" %d %d %lld", &n, &m, &budget);

    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            scanf(" %lld", &sum[i][j]);

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

long long select(int a, int b, int c, int d){
    long long base = sum[c][d];

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

    sol_area = 0;

    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            for (int k=i; k < n; k++){

                if (m * (k - i + 1) < sol_area){
                    continue;
                }

                for (int l=j; l < m; l++){
                    long long cost = select(i, j, k, l);
                    int area = (k - i + 1) * (l - j + 1);

                    if (cost <= budget){
                        if (area > sol_area){
                            sol_area = area;
                            sol_cost = cost;
                        } else if (area == sol_area){
                            sol_cost = min(sol_cost, cost);
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &T);

    for (int t=1; t <= T; t++){

        init();
        solve();

        printf("Case #%d: %lld %lld\n", t, sol_area, sol_cost);
    }


}
