#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 11;

int tc, n;
int ans[maxn][1 << maxn];
int inp_x[maxn], inp_y[maxn];
int w_x, w_y, s_x, s_y;

void reset(void){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < (1 << maxn); j++){
            ans[i][j] = -1;
        }
    }
}

void init(void){

    reset();

    scanf(" %d %d", &w_x, &w_y);
    scanf(" %d %d", &s_x, &s_y);

    scanf(" %d", &n);

    for (int i=0; i < n; i++){
        scanf(" %d %d", &inp_x[i], &inp_y[i]);
    }

}

int dist(int a, int b){
    if (b == -1){
        return abs(inp_x[a] - s_x) + abs(inp_y[a] - s_y);
    }
    return abs(inp_x[a] - inp_x[b]) + abs(inp_y[a] - inp_y[b]);
}

int solve(int ind, int mask){
    if (mask == (1 << n) - 1){
        return dist(ind, -1);
    }

    if (ans[ind][mask] != -1){
        return ans[ind][mask];
    }

    int best = 1e9;

    for (int i=0; i < n; i++){
        if (!(mask & (1 << i))){
            best = min(best, solve(i, mask | (1 << i)) + dist(ind, i));
        }
    }

    return ans[ind][mask] = best;
}

int start(void){
    int best = 1e9;

    for (int i=0; i < n; i++){
        best = min(best, solve(i, 1 << i) + dist(i, -1));
    }

    return best;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){
        init();
        printf("The shortest path has length %d\n", start());
    }
}
