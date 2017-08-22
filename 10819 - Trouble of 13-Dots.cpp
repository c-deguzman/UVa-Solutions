#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
const int maxm = 10305;

int n, m;
int ans[maxn][maxm];
pair <int, int> inp[maxn];

void init(void){
    for (int i=0; i <= n; i++){
        for (int j=0; j < m + 205; j++){
            ans[i][j] = -1;
        }
    }
}

int solve(int ind, int cost){
    if (cost - 200 > m){
        return -1e9;
    }

    if (ind == n){
        if (cost - (cost > 2000 ? 200 : 0) <= m){
            return 0;
        }
        return -1e9;
    }

    if (ans[ind][cost]!= -1){
        return ans[ind][cost];
    }

    return ans[ind][cost] = max(solve(ind + 1, cost + inp[ind].first) + inp[ind].second, solve(ind + 1, cost));
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &m, &n) == 2){
        init();

        for (int i=0; i < n; i++){
            scanf(" %d %d", &inp[i].first, &inp[i].second);
        }

        printf("%d\n", solve(0, 0));
    }
}
