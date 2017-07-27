#include <iostream>
#include <cstdio>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){
        int pow[22], k, deg;
        long long d;

        scanf(" %d", &deg);

        for (int i=0; i <= deg; i++){
            scanf(" %d", &pow[i]);
        }

        scanf(" %lld %d", &d, &k);

        long long solve = 0, terms = 0;

        while (solve < k){
            terms++;
            solve = terms * (d + terms * d) / 2;
        }

        long long ans = 0, base = 1;

        for (int i=0; i <= deg; i++, base *= terms){
            ans += base * pow[i];
        }

        printf("%lld\n", ans);

    }
}
