#include <iostream>
#include <cstdio>

using namespace std;

int test_case;
int n, b, m, t;

int towers[25];
int comm_serv[15][25];

int count_ones(int num){
    int total = 0;

    if (num & 1){
        total--;
    }

    while (num){
        if (num & 1){
            total++;
        }
        num >>= 1;
    }

    return total;
}

int total_cover(int bitmask){
    int total = 0;

    for (int i=1; i <= n; i++){
        if (bitmask & (1 << i)){
            total += towers[i];
        }
    }

    for (int i=0; i < m; i++){
        int occ = 0;

        for (int j=1; j <= comm_serv[i][0]; j++){
            if (bitmask & (1 << comm_serv[i][j])){
                occ++;
            }
        }

        if (occ > 1){
            total -= (occ - 1) * comm_serv[i][22];
        }
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &b) == 2){

        if (test_case){
            printf("\n");
        }

        if (n == 0 && b == 0){
            break;
        }

        printf("Case Number  %d\n", ++test_case);

        for (int i=1; i <= n; i++){
            scanf(" %d", &towers[i]);
        }

        scanf(" %d", &m);

        for (int i=0; i < m; i++){
            scanf(" %d", &comm_serv[i][0]);

            for (int j=1; j <= comm_serv[i][0]; j++){
                scanf(" %d", &comm_serv[i][j]);
            }

            scanf(" %d", &comm_serv[i][22]);
        }

        int best_mask, best_score = -1;

        for (int chose = 1; chose < (1 << (n + 1)); chose++){

            if (count_ones(chose) != b){
                continue;
            }

            int local_score = total_cover(chose);

            if (local_score > best_score){
                best_score = local_score;
                best_mask = chose;
            }

        }

        printf("Number of Customers: %d\n", best_score);
        printf("Locations recommended:");

        for (int i=1; i <= n; i++){
            if (best_mask & (1 << i)){
                printf(" %d", i);
            }
        }

        printf("\n");
    }
}
