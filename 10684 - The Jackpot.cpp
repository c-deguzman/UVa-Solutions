#include <iostream>
#include <cstdio>

using namespace std;

int n, inp;

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &n) == 1){

        if (!n){
            break;
        }

        int best = -1e9;
        int streak = 0;

        for (int i=0; i < n; i++){
            scanf(" %d", &inp);
            best = max(best, streak = max(inp, streak + inp));
        }

        if (best <= 0){
            printf("Losing streak.\n");
        } else {
            printf("The maximum winning streak is %d.\n", best);
        }
    }
}
