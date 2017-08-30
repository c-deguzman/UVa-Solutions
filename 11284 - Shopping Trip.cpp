#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 52;
const int maxp = 13;

int tc, m, n, p, total_save;
int inp_arr[4];

int stores[maxp];
int save[maxn];

int apsp[maxn][maxn];
int ans[maxp][1 << maxp];

void init(void){
    for (int i=0; i < maxn; i++){
        save[i] = 0;
        for (int j=0; j < maxn; j++){
            apsp[i][j] = 1e9;
        }
    }

    for (int i=0; i < maxp; i++){
        for (int j=0; j < (1 << maxp); j++){
            ans[i][j] = -1e9;
        }
    }
}

int solve(int ind, int mask){
    if (ans[ind][mask] != -1e9){
        return ans[ind][mask];
    }

    int best = apsp[stores[ind]][0] * -1;

    for (int i=0; i < p; i++){
        if (!(mask & (1 << i))){
            best = max(best, solve(i, mask | (1 << i)) + save[stores[i]] - apsp[stores[ind]][stores[i]]);
        }
    }

    return ans[ind][mask] = best;
}

int start(void){

    int best = 0;

    for (int i=0; i < p; i++){
        best = max(best, solve(i, 1 << i) + save[stores[i]] - apsp[stores[i]][0]);
    }

    return best;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){
        scanf(" %d %d", &n, &m);

        init();

        for (int i=0; i < m; i++){
            scanf(" %d %d %d.%d", &inp_arr[0], &inp_arr[1], &inp_arr[2], &inp_arr[3]);

            int cost = inp_arr[2] * 100 + inp_arr[3];

            if (cost < apsp[inp_arr[0]][inp_arr[1]]){
                apsp[inp_arr[0]][inp_arr[1]] = cost;
                apsp[inp_arr[1]][inp_arr[0]] = cost;
            }
        }

        scanf(" %d", &p);

        for (int i=0; i < p; i++){
            scanf(" %d %d.%d", &inp_arr[0], &inp_arr[1], &inp_arr[2]);
            save[inp_arr[0]] = inp_arr[1] * 100 + inp_arr[2];
            stores[i] = inp_arr[0];
        }

        for (int k=0; k <= n; k++){
            for (int i=0; i <= n; i++){
                for (int j=0; j <= n; j++){
                    apsp[j][i] = apsp[i][j] = min(apsp[i][j], apsp[i][k] + apsp[k][j]);
                }
            }
        }

        if ((total_save = start()) <= 0){
            printf("Don't leave the house\n");
        } else {
            printf("Daniel can save $%d.%d%d\n", total_save / 100, (total_save / 10) % 10, total_save % 10);
        }

    }
}
