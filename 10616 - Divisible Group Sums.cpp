#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 205;
const int maxm = 15;
const int maxd = 25;

long long ans[maxn][maxm][maxd];
long long inp[maxn];

int n, q, m, d;

void init(void){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxm; j++){
            for (int k=0; k < maxd; k++){
                ans[i][j][k] = -1;
            }
        }
    }
}

long long solve(int ind, int taken, int rem){
    if (ind == n){
        if (rem == 0 && taken == m){
            return 1;
        } else {
            return 0;
        }
    }

    if (ans[ind][taken][rem] != -1){
        return ans[ind][taken][rem];
    }

    long long comb = solve(ind + 1, taken, rem);

    if (taken < m){
        comb += solve(ind + 1, taken + 1, (((rem + inp[ind]) % d) + d) % d);
    }

    return ans[ind][taken][rem] = comb;
}

int main()
{
    ios::sync_with_stdio(false);

    for (int t=1; (scanf(" %d %d", &n, &q) == 2); t++){
        if (!n && !q){
            break;
        }

        for (int i=0; i < n; i++){
            scanf(" %lld", &inp[i]);
        }

        printf("SET %d:\n", t);
        for (int i=1; i <= q; i++){
            init();
            scanf(" %d %d", &d, &m);
            printf("QUERY %d: %lld\n", i, solve(0,0,0));
        }

    }

}
