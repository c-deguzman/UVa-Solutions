#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 30005;

long long ans[maxn];
int coins[] = {1, 5, 10, 25, 50};
int inp;

void init(void){
    ans[0] = 1;

    for (int i=0; i < 5; i++){
        for (int j=coins[i]; j < maxn; j++){
            ans[j] += ans[j - coins[i]];
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    init();

    while (scanf(" %d", &inp) == 1){
        if (ans[inp] == 1){
            printf("There is only 1 way");
        } else {
            printf("There are %lld ways", ans[inp]);
        }
        printf(" to produce %d cents change.\n", inp);
    }
}
