#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int maxn = 9;

int n, tc;
int x_co[maxn], y_co[maxn];
double ans[maxn][1 << maxn];
int last[maxn][1 << maxn];

double global_best;

double dist(int a, int b){
    double x_sq = (x_co[a] - x_co[b]) * (x_co[a] - x_co[b]);
    double y_sq = (y_co[a] - y_co[b]) * (y_co[a] - y_co[b]);

    return sqrt(x_sq + y_sq) + 16;
}

void init(void){
    for (int i=0; i < n; i++){
        scanf(" %d %d", &x_co[i], &y_co[i]);

        for (int j=0; j < (1 << maxn); j++){
            last[i][j] = ans[i][j] = -1;
        }
    }
}

double rec(int ind, int mask){

    if (mask == ((1 << n) - 1)){
        return 0;
    }

    if (ans[ind][mask] > 0){
        return ans[ind][mask];
    }

    double best = 1e9;
    int best_ind = -1;

    for (int i=0; i < n; i++){
        if (!(mask & (1 << i))){
            double attempt = rec(i, mask | (1 << i)) + dist(ind, i);

            if (attempt < best){
                best = attempt;
                best_ind = i;
            }
        }
    }

    last[ind][mask] = best_ind;

    return ans[ind][mask] = best;

}

int start(void){
    double best = 1e9;
    int best_start = -1;

    for (int i=0; i < n; i++){
        double attempt = rec(i, 1 << i);



        if (attempt < best){
            best = attempt;
            best_start = i;
        }
    }

    global_best = best;
    return best_start;
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &n) == 1){
        if (!n){
            break;
        }

        init();
        int ind = start();
        int mask = (1 << ind);

        printf("**********************************************************\n");
        printf("Network #%d\n", ++tc);

        while (true){

            int next = last[ind][mask |= (1 << ind)];

            if (next == -1){
                printf("Number of feet of cable required is %.2f.\n", global_best);
                break;
            }

            printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", x_co[ind], y_co[ind], x_co[next], y_co[next], dist(ind, next));

            ind = next;
        }
    }
}
