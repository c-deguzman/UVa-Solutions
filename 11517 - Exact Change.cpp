#include <iostream>
#include <cstdio>

using namespace std;

const int max_val = 20005;
const int maxn = 105;
int tc, n, goal, inp;

int ans[max_val];

void init(void){
    for (int i=0; i < max_val; i++){
        ans[i] = 1e9;
    }
    ans[0] = 0;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){
        scanf(" %d %d", &goal, &n);

        init();

        for (int x=0; x < n; x++){
            scanf(" %d", &inp);
            for (int i = max_val - 1; i >= 0; i--){
                if (i - inp < 0){
                    break;
                }
                ans[i] = min(ans[i - inp] + 1, ans[i]);
            }
        }

        for (int i=goal; i < max_val; i++){
            if (ans[i] < 1e9){
                printf("%d %d\n", i, ans[i]);
                break;
            }
        }
    }

}
