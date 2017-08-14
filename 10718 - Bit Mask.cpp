#include <iostream>
#include <cstdio>

using namespace std;

long long n, l, u;

long long reconcile(long long num){

    if (l <= num && num <= u){
        return num;
    }

    for (int i=31; i >= 0; i--){
        long long diff = l - num;
        long long bit = ((long long) 1 << i);

        if (bit <= diff && (num | bit) <= u){
            num |= bit;
        } else if ( (num | (bit - 1)) < l){
            num |= bit;
        }
    }

    return num;
}

long long solve(void){

    long long num = 0;

    bool match = true;

    for (int i=31; i >= 0; i--){
        long long bit = ((long long) 1 << i);

        if (match && (l & bit & u)){
            num |= bit;
        } else if (match && (l & bit) != (u & bit)){
            match = false;
        }

        if (!match){
            if (!(n & bit)){
                if ((num | bit) <= u){
                    num |= bit;
                }
            }
        }
    }

    return reconcile(num);
}

int main()
{

    ios::sync_with_stdio(false);

    while (scanf(" %lld %lld %lld", &n, &l, &u) == 3){
        printf("%lld\n", solve());
    }
}
