#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int sz;
long long int p;

int main()
{
    while (true){
        scanf(" %d %lld", &sz, &p);

        if (sz == 0 && p == 0){
            break;
        }

        int centre = sz / 2 + 1;

        long long int sq = (long long int) sqrt(p) - 1;

        while ((sq + 1) * (sq + 1) <= p){
            sq++;
        }

        if (!(sq % 2)){
            sq--;
        }


        // 0 - left
        // 1 - down
        // 2 - right
        // 3 - up
        int stage = -1;
        int x, y;

        x = y = centre + (int) (sq / 2);

        long long int tile = sq * sq;

        while (tile < p){
            if (stage == -1){
                y++;
                stage++;
                tile++;
                continue;
            }

            if (stage == 0){

                if (tile + sq < p){
                    tile += sq;
                    x -= (int) sq;
                    stage++;
                    continue;
                } else {
                    x -= (int) (p - tile);
                    break;
                }
            }

            if (stage == 1){

                if (tile + sq + 1 < p){
                    tile += sq + 1;
                    y -= (int) sq + 1;
                    stage++;
                    continue;
                } else {
                    y -= (int) (p - tile);
                    break;
                }
            }

            if (stage == 2){

                if (tile + sq + 1 < p){
                    tile += sq + 1;
                    x += (int) sq + 1;
                    stage++;
                    continue;
                } else {
                    x += (int) (p - tile);
                    break;
                }
            }

            if (stage == 3){

                if (tile + sq + 1 < p){
                    tile += sq + 1;
                    y += (int) sq + 1;

                    sq++;
                    stage = -1;
                    continue;
                } else {
                    y += (int) (p - tile);
                    break;
                }
            }
        }

        printf("Line = %d, column = %d.\n", y, x);

    }


}
