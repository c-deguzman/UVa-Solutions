#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
const int maxk = 105;

int n, k;
int ans[maxn][maxk];

void init(void){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxk; j++){
            ans[i][j] = -1;
        }
    }
}

int solve(int rem, int left){

    if (left == 1){
        return 1;
    }

    if (ans[rem][left] != -1){
        return ans[rem][left];
    }

    int total = 0;

    for (int i=0; i <= rem; i++){
        total += solve(rem - i, left - 1);
        total %= 1000000;
    }

    return ans[rem][left] = total;
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &k) == 2){
        if (n == 0 && k == 0){
            break;
        }
        init();
        printf("%d\n", solve(n, k));
    }

}
