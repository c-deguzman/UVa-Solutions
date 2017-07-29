#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int field[500][500];
int m;

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &m) == 1){
        for (int i=0; i < m; i++){
            for (int j=0; j < m; j++){
                char inp_dig;
                scanf(" %c", &inp_dig);
                field[i][j] = inp_dig - '0';
            }
        }

        int global_best = 0;

        for (int i=0; i < m; i++){
            for (int j=0; j < m; j++){

                if (field[i][j] != 1){
                    continue;
                }

                int local_best = 505;

                for (int k=0; k < m; k++){
                    for (int l=0; l < m; l++){
                        if (field[k][l] != 3){
                            continue;
                        }

                        local_best = min(local_best, (int)abs(i - k) + (int) abs(j - l));
                    }
                }

                global_best = max(global_best, local_best);
            }
        }

        printf("%d\n", global_best);
    }

}
