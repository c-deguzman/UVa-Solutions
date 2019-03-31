#include <iostream>
#include <cstdio>

using namespace std;

const int max_n = 10005;

int soln[max_n][10];

void pre_solve(){
    for (int i=1; i < max_n; i++){

        int curr = i;

        while (curr){
            soln[i][curr % 10]++;
            curr /= 10;
        }

        for (int j=0; j < 10; j++){
            soln[i][j] += soln[i - 1][j];
        }
    }
}

void solve(int value){
    for (int i=0; i < 9; i++){
        printf("%d ", soln[value][i]);
    }
    printf("%d\n", soln[value][9]);
}

int main()
{
    ios::sync_with_stdio(false);

    pre_solve();

    int cases;
    scanf("%d", &cases);

    while (cases--){
        int value;
        scanf("%d", &value);
        solve(value);
    }
}
