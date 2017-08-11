#include <iostream>
#include <cstdio>

using namespace std;

int tc, n;
int coins[1005];

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){
        scanf(" %d", &n);

        for (int i=0; i < n; i++){
            scanf(" %d", &coins[i]);
        }

        int coin_types = 1, coin_sum = 0;

        for (int i=0; i < n - 1; i++){
            if (coin_sum + coins[i] >= coins[i + 1]){
                continue;
            }

            coin_sum += coins[i];
            coin_types++;
        }

        printf("%d\n", coin_types);
    }

}
