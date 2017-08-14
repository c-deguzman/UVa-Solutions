#include <iostream>
#include <cstdio>

using namespace std;

long long n, l, u;

long long solve(void){

    long long num = 0;

    for (int i=31; i >= 0; i--){
        long long bit = ((long long) 1 << i);

        if (((n & bit) && ((num | bit) <= l)) ||
            (!(n & bit) && ((num | bit) <= u))){
            num |= bit;
        }
    }

    return num;
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %lld %lld %lld", &n, &l, &u) == 3){
        printf("%lld\n", solve());
    }
}
