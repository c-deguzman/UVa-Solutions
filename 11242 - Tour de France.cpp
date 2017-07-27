#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int f, r;
int front_arr[15], rear_arr[15];
double d_rs[15 * 15];

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &f, &r) == 2){
        for (int i=0; i < f; i++){
            scanf(" %d", &front_arr[i]);
        }

        for (int i = 0; i < r; i++){
            scanf(" %d", &rear_arr[i]);
        }

        int d_rs_len = 0;

        for (int i = 0; i < f; i++){
            for (int j=0; j < r; j++){
                double n = (double) front_arr[i];
                double m = (double) rear_arr[j];

                double d_r = n / m;

                d_rs[d_rs_len] = d_r;
                d_rs_len++;
            }
        }

        sort(d_rs, d_rs + d_rs_len);

        double max_spread = 0;

        for (int i=1; i < d_rs_len; i++){
            max_spread = max(max_spread, d_rs[i] / d_rs[i - 1]);
        }

        printf("%.2f\n", max_spread);
    }
}
