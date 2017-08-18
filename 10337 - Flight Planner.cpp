#include <iostream>
#include <cstdio>

using namespace std;

int TC, n;

const int climb = 60;
const int hold = 30;
const int sink = 20;

int wind[15][1005];
int ans[15][1005];

void init(void){
    scanf(" %d", &n);

    for (int i=9; i >= 0; i--){
        for (int j=0; j < n / 100; j++){
            ans[i][j] = -1;
            scanf(" %d", &wind[i][j]);
        }
    }
}

int solve(int alt, int pos){
    if (pos >= (n / 100)){
        if (!alt){
            return 0;
        } else {
            return 1e9;
        }
    }

    if (ans[alt][pos] != -1){
        return ans[alt][pos];
    }

    int best = 1e9;

    if (alt < 9){
        best = min(best, solve(alt + 1, pos + 1)+ climb);
    }

    best = min(best, solve(alt, pos + 1) + hold);

    if (alt > 0){
        best = min(best, solve(alt - 1, pos + 1) + sink);
    }

    return ans[alt][pos] = (best - wind[alt][pos]);
}


int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &TC);

    while (TC--){
        init();
        printf("%d\n\n", solve(0, 0));
    }
}
