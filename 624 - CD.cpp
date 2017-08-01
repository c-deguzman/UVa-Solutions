#include <iostream>
#include <cstdio>

using namespace std;

int n, m;

int cds[25];

int best;
int best_mask;

void try_all(int ind, int len, int bitmask){
    if (len > n){
        return;
    }

    if (len <= n && len > best){
        best = len;
        best_mask = bitmask;
    }

    for (int i=ind; i < m; i++){
        try_all(i + 1, len + cds[i], bitmask | (1 << i));
    }

    return;
}

int main()
{

    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &m) == 2){

        best = best_mask = 0;

        for (int i=0; i < m; i++){
            scanf(" %d", &cds[i]);
        }

        try_all(0, 0, 0);

        for (int i=0; i < m; i++){
            if (best_mask & (1 << i)){
                printf("%d ", cds[i]);
            }
        }

        printf("sum:%d\n", best);

    }
}
