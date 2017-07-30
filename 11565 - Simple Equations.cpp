#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int t;
int a, b, c;

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){
        scanf(" %d %d %d", &a, &b, &c);

        bool found_sol = false;

        for (int x = (int) sqrt(c) * -1; x <= (int) sqrt(c) && !found_sol; x++){
            if (x * x > c || x == 0 ||  x > b){
                continue;
            }

            for (int y = x + 1; y <= a - x && !found_sol; y++){
                if (x * x + y * y > c || y == 0 || x * y > b){
                    continue;
                }

                int z = a - x - y;


                if (!((b == x * y * z) && (x * x + y * y + z * z == c) && (x < y && y < z))){
                    continue;
                }

                if (!found_sol){
                    printf("%d %d %d\n", x, y, z);
                    found_sol = true;
                }
            }
        }

        if (!found_sol){
            printf("No solution.\n");
        }
    }
}
