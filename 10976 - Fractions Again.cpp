#include <iostream>
#include <cstdio>

using namespace std;

int k;

int main()
{
    ios::sync_with_stdio(false);

    while(scanf(" %d", &k) == 1){

        int x = k, occ = 0;

        while (true){
            x++;

            if ((k * x) % (x - k)){
                continue;
            }

            int y = (k * x) / (x - k);

            occ++;

            if (x == y){
                break;
            }
        }

        printf("%d\n", occ);

        x = k;

        while (true){
            x++;

            if ((k * x) % (x - k)){
                continue;
            }

            int y = (k * x) / (x - k);

            printf("%d/%d = %d/%d + %d/%d\n", 1, k, 1, y, 1, x);

            if (x == y){
                break;
            }
        }
    }
}
