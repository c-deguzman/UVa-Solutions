#include <iostream>
#include <cstdio>

using namespace std;

int s, b;

int main()
{
    while (true){
        scanf(" %d %d", &s, &b);

        if (s == 0 && b == 0){
            break;
        }

        int left_surv[100005];
        int right_surv[100005];

        for (int i = 0; i <= s + 1; i++){
            left_surv[i] = i - 1;
            right_surv[i] = i + 1;
        }

        right_surv[s + 1] = -1;

        for (int i=0 ; i != b; i++){
            int l, r;
            scanf(" %d %d", &l, &r);

            int find_left = left_surv[l];
            int find_right = right_surv[r];

            int new_left = left_surv[find_right] = find_left;
            int new_right = right_surv[find_left] = find_right;


            if (new_left < 1){
                printf("* ");
            } else {
                printf("%d ", new_left);
            }

            if (new_right > s){
                printf("*\n");
            } else {
                printf("%d\n", new_right);
            }
        }

        printf("-\n");



    }
}
