#include <iostream>
#include <cstdio>

using namespace std;

bool first = true;

int main()
{
    ios::sync_with_stdio(false);

    int n;
    while (scanf(" %d", &n) == 1){

        if (!n){
            break;
        }

        if (!first){
             printf("\n");
        } else {
            first = false;
        }


        int nums[55];

        for (int i=0; i < n; i++){
            scanf(" %d", &nums[i]);
        }

        for (int a = 0; a < n - 5; a++){
            for (int b = a + 1; b < n - 4; b++){
                for (int c = b + 1; c < n - 3; c++){
                    for (int d = c + 1; d < n - 2; d++){
                        for (int e = d + 1; e < n - 1; e++){
                            for (int f = e + 1; f < n; f++){
                                printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c], nums[d], nums[e], nums[f]);
                            }
                        }
                    }
                }
            }
        }
    }
}
