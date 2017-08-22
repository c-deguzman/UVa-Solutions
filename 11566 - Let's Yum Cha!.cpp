#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 15;
const int maxx = 105;
const int maxt = 20;
const int maxk = 105;
const int max_price = 105;

int n, x, t, k;

int inp_price[maxk];
int inp_fav[maxk];
int inp_fav_i;

int ans[maxk][maxn *  max_price][2 * maxn];

int serv_charge(int val){
    int tea = t * (n + 1);
    int res = (val + tea) + (val + tea) / 10;

    if ((val + tea) % 10){
        res++;
    }

    return res;
}

int solve(int ind, int cost, int dishes){
    if (dishes > 2 * (n + 1) || serv_charge(cost) > x * (n + 1)){
        return -1e9;
    }

    if (ind == k){
        return 0;
    }

    if (ans[ind][cost][dishes] != -1){
        return ans[ind][cost][dishes];
    }

    int best = -1e9;

    best = max(best, solve(ind + 1, cost, dishes));
    best = max(best, solve(ind + 1, cost + inp_price[ind], dishes + 1) + inp_fav[ind]);
    best = max(best, solve(ind + 1, cost + inp_price[ind] * 2, dishes + 1 * 2) + inp_fav[ind] * 2);

    return ans[ind][cost][dishes] = best;
}

void init(void){
    for (int i=0; i < maxk; i++){
        for (int j=0; j < maxn * max_price; j++){
            for (int k=0; k <  2 * maxn; k++){
                ans[i][j][k] = -1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d %d %d", &n, &x, &t, &k) == 4){
        if (!n && !x && !t && !k){
            break;
        }

        init();

        for (int i=0; i < k; i++){
            scanf(" %d", &inp_price[i]);

            inp_fav[i] = 0;

            for (int j=0; j <= n; j++){
                scanf(" %d", &inp_fav_i);
                inp_fav[i] += inp_fav_i;
            }
        }

        printf("%.2f\n", (double)solve(0, 0, 0) / (double) (n + 1));
    }

}
