#include <iostream>
#include <cstdio>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &n) == 1){
        if (!n){
            break;
        }

        bool first_num = false;

        for (int i=0; i < n; i++){
            int inp;
            scanf(" %d", &inp);

            if (inp && first_num){
                printf(" %d", inp);
            } else if (inp){
                printf("%d", inp);
                first_num = true;
            }
        }

        if (!first_num){
            printf("%d", 0);
        }
        printf("\n");
    }
}
