#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int n, tc;
int ring[20];

bool done[400];
bool sieve[400];

void build(void){
    const int sieve_size = 400;

    for (int i=2; i < sieve_size; i++){
        if (done[i]){
            continue;
        }

        done[i] = sieve[i] = true;

        for (int j= i * 2; j < sieve_size; j += i){
            done[j] = true;
        }
    }
}

void print_sol(void){
    printf("%d", 1);

    for (int i=1; i < n; i++){
        printf(" %d", ring[i]);
    }

    printf("\n");
}

void backtrack(int ind, int bitmask){
    if (ind == n && sieve[ring[n - 1] + 1]){
        print_sol();
    }

    for (int i = 1; i < n; i++){
        if (!(bitmask & (1 << i))){
            if (sieve[ring[ind - 1] + (i + 1)]){
                ring[ind] = i + 1;
                backtrack(ind + 1, bitmask | (1 << i));
            }
        }
    }
}

int main()
{

    ios::sync_with_stdio(false);

    build();

    while (scanf(" %d", &n) == 1){
        ring[0] = 1;

        if (tc){
            printf("\n");
        }

        printf("Case %d:\n", ++tc);

        backtrack(1, 0);
    }

}
