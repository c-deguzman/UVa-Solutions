#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 20005;

int n, m;
int knights[maxn];
int heads[maxn];

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &m) == 2){
        if (n == 0 && m == 0){
            break;
        }

        for (int i=0; i < n; i++){
            scanf(" %d", &heads[i]);
        }

        for (int i=0; i < m; i++){
            scanf(" %d", &knights[i]);
        }

        sort(heads, heads + n);
        sort(knights, knights + m);

        int k_ind = 0;
        int h_ind = 0;

        int cost = 0;

        while (k_ind < m && h_ind < n){
            if (heads[h_ind] <= knights[k_ind]){
                cost += knights[k_ind];
                h_ind++;
                k_ind++;
            } else {
                k_ind++;
            }
        }

        if (h_ind != n){
            printf("Loowater is doomed!\n");
        } else {
            printf("%d\n", cost);
        }

    }
}
