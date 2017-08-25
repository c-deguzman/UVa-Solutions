#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxm = 45;
const int maxs = 305;
const int inf = 1e9;

int tc, m, s;
int inp_it, inp_reg;
int ans[maxs][maxs];

void init(void){
    for (int i=0; i <= s; i++){
        for (int j=0; j <= s; j++){
            ans[i][j] = inf;
        }
    }
    ans[0][0] = 0;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){
        scanf(" %d %d", &m, &s);

        init();

        for (int a=0; a < m; a++){
            scanf(" %d %d", &inp_reg, &inp_it);

            for (int i=0; i <= s; i++){
                for (int j=0; j <= s; j++){

                    int l_it = i + inp_it;
                    int l_reg = j + inp_reg;

                    if (l_it > s || l_reg > s){
                        continue;
                    }

                    ans[l_it][l_reg] = min(ans[l_it][l_reg], ans[i][j] + 1);
                }
            }
        }

        int lo = 1e9;

        for (int x = 0; x <= s; x++){
            int y_sq = s * s - x * x;
            int y = (int) floor(sqrt(y_sq));

            if (y * y + x * x == s * s){
                lo = min(lo, ans[x][y]);
            }
        }

        if (lo >= 1e9){
            printf("not possible\n");
        } else {
            printf("%d\n", lo);
        }

    }
}
