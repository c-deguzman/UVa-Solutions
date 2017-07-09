#include <iostream>
#include <cstdio>
#include <bitset>

using namespace std;

const int mil = 1000000;

int n,m;

int main()
{
    while (true){
        scanf(" %d %d", &n, &m);

        if (n == 0 && m == 0){
            break;
        }

        bitset <1000005> bits;

        bool overlap = false;

        for (int i=0; i != n; i++){
            int start, finish;
            scanf(" %d %d", &start, &finish);

            if (!overlap){
                for (int j = start; j < finish && !overlap; j++){
                    if (bits[j]){
                        overlap = true;
                    } else {
                        bits.flip(j);
                    }
                }
            }
        }

        for (int i=0; i != m; i++){
            int start, finish, repeat;

            scanf(" %d %d %d", &start, &finish, &repeat);

            if (!overlap){
                for (int mult = 0; start + repeat * mult <= mil && !overlap; mult++){
                    for (int j = start; j < finish; j++){
                        int curr_bit = j + repeat * mult;

                        if (curr_bit > mil){
                            break;
                        }

                        if (bits[curr_bit]){
                            overlap = true;
                        } else {
                            bits.flip(curr_bit);
                        }
                    }
                }
            }
        }

        if (!overlap){
            printf("NO ");
        }
        printf("CONFLICT\n");
    }

}
