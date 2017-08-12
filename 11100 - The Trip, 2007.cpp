#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

const int maxn = 10005;

int n;
int bags[maxn];
vector < int > ans[maxn];

int max_mult;

void solve(void){
    for (int i=0; i < max_mult; i++){
        ans[i].clear();
    }

    int ans_ind = 0;
    for (int i=0; i < n; i++){
        ans[ans_ind].push_back(bags[i]);
        ans_ind = (ans_ind + 1) % max_mult;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &n) == 1){
        if (n == 0){
            break;
        }

        max_mult = 0;

        for (int i=0; i < n; i++){
            scanf(" %d", &bags[i]);
        }

        sort(bags, bags + n);

        int mult = 1;

        for (int i=1; i <= n; i++){
            max_mult = max(max_mult, mult);
            if (bags[i] == bags[i - 1]){
                mult++;
            } else {
                mult = 1;
            }
        }

        printf("%d\n", max_mult);

        solve();

        for (int i=0; i < max_mult; i++){
            for (int j=0; j < ans[i].size(); j++){
                if (!j){
                    printf("%d", ans[i][j]);
                } else {
                    printf(" %d", ans[i][j]);
                }
            }

            printf("\n");
        }

        printf("\n");

    }

}
