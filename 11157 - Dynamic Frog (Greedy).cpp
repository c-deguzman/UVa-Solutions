#include <iostream>
#include <cstdio>

using namespace std;

int T;
int n, d;
const int maxn = 105;
bool taken[maxn], small[maxn];
int rocks[maxn];

void init(void){
    scanf(" %d %d", &n, &d);

    rocks[0] = 0;
    rocks[n + 1] = d;

    small[0] = small[n + 1] = false;

    for (int i=1; i <= n; i++){
        taken[i] = false;

        char sz;
        scanf(" %c-%d", &sz, &rocks[i]);

        small[i] = (sz == 'S');
    }
}

int solve(void){
    int mini_max = 0;

    int curr_pos = 0;

    for (int i=1; i <= n + 1; i++){
        if (!small[i]){
            mini_max = max(mini_max, rocks[i] - rocks[i - 1]);
        } else {
            i++;
            mini_max = max(mini_max, rocks[i] - rocks[i - 2]);
            taken[i] = true;
        }
    }

    for (int i = n; i >= 0; i--){
        if (!small[i] || !taken[i]){
            mini_max = max(mini_max, rocks[i + 1] - rocks[i]);
        } else {
            i--;
            mini_max = max(mini_max, rocks[i + 2] - rocks[i]);
            taken[i] = true;
        }
    }

    return mini_max;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &T);

    for (int t=1; t <= T; t++){
        init();
        printf("Case %d: %d\n", t, solve());
    }
}
