#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool input(int & value){
    scanf("%d", &value);
    return value;
}

void solve(int value){

    int divisor_sum = 0;

    for (int i=1; i <= (int) ceil(sqrt((float) value)); i++){
        if (value % i == 0){
            int lo = i, hi = value / i;

            if (lo <= hi && hi != 1){
                divisor_sum += lo;
            }

            if (hi > lo && hi != value){
                divisor_sum += hi;
            }
        }
    }

    printf("%5d  ", value);
    if (divisor_sum < value){
        printf("DEFICIENT\n");
    } else if (divisor_sum == value){
        printf("PERFECT\n");
    } else {
        printf("ABUNDANT\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);

    printf("PERFECTION OUTPUT\n");

    int value;
    while (input(value)){
        solve(value);
    }

    printf("END OF OUTPUT\n");
}
