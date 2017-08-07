#include <iostream>
#include <cstdio>

using namespace std;

int field[505][505];
int n, m, q;
int l, u;

int opt_start(int row){
    int hi = m - 1;
    int lo = 0;

    int ans = m;

    while (lo <= hi){
        int mid = (lo + hi) / 2;

        if (field[row][mid] >= l){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

bool poss(int side_len){
    for (int i=0; i < n - side_len; i++){
        for (int j=opt_start(i); j < m - side_len; j++){
            if (field[i][j] >= l &&
                field[i + side_len][j + side_len] <= u){
                return true;
            } else {
                break;
            }
        }
    }

    return false;
}

void solve(void){


    int hi = min(m, n) - 1;
    int lo = 0;

    int ans = -1;

    while (lo <= hi){
        int mid = (lo + hi) / 2;

        if (poss(mid)){
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    printf("%d\n", ans + 1);
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &m) == 2 && n && m){

        for (int i=0; i < n; i++){
            for (int j=0; j < m; j++){
                scanf(" %d", &field[i][j]);
            }
        }

        scanf(" %d", &q);

        while (q--){
            scanf(" %d %d", &l, &u);
            solve();
        }

        printf("-\n");
    }

}
