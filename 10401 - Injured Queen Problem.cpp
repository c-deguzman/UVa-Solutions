#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>

using namespace std;

const int maxn = 15 + 2;
int n;
char cols[maxn];

long long int memo[maxn][maxn];

bool input(){
    if (scanf(" %s", &cols) != 1) return false;
    n = strlen(cols);

    return true;
}

void reset(){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxn; j++){
            memo[i][j] = -1;
        }
    }
}


long long int solve(int col, int last_val){
    long long int total = 0L;

    if (memo[col][last_val] != -1) return memo[col][last_val];

    if (col == n){
        return 1L;
    } else if (cols[col] != '?'){
        int row_val = cols[col] - '0';

        if (row_val < 0  || row_val > 9){
            row_val = cols[col] - 'A' + 10;
        }

        if (abs(row_val - last_val) <= 1 && col){
            total = 0L;
        } else {
            total = solve(col + 1, row_val);
        }

    } else {
        for (int i=1; i <= n; i++){
            if (abs(last_val - i) <= 1 && col) continue;
            total += solve(col + 1, i);
        }
    }

    return memo[col][last_val] = total;
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        reset();
        printf("%lld\n", solve(0, 0));
    }
}
