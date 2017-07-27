#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int n, m, t, sum_len;
int nums[1005];
int sums[1000005];

void init(void){

    sum_len = 0;

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            if (i == j){
                continue;
            }

            sums[sum_len] = nums[i] + nums[j];
            sum_len++;
        }
    }

    sort(sums, sums + sum_len);
}

int solve_close(int q){
    int last_best = 1e9;

    for (int i=0; i != sum_len; i++){
        if (abs(last_best - q) < abs(sums[i] - q)){
            return last_best;
        } else {
            last_best = sums[i];
        }
    }

    return last_best;
}

int main()
{
    while (scanf(" %d", &n) == 1){
        t++;
        if (!n){
            break;
        }

        printf("Case %d:\n", t);

        for (int i=0; i < n; i++){
            scanf(" %d", &nums[i]);
        }

        init();

        scanf(" %d", &m);

        for (int i=0; i < m; i++){
            int q;
            scanf(" %d", &q);
            printf("Closest sum to %d is %d.\n", q, solve_close(q));
        }
    }
}
