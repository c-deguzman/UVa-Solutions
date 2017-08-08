#include <iostream>
#include <cstdio>

using namespace std;

int T, n;
int rungs[100005];
int min_k, max_k;

bool poss(int k){
    if (k < rungs[0]){
        return false;
    } else if (k == rungs[0]){
        k--;
    }

    for (int i=1; i < n; i++){
        if (k == rungs[i] - rungs[i - 1]){
            k--;
        } else if (k < rungs[i] - rungs[i - 1]){
            return false;
        }
    }

    return true;
}

void solve(void){
    int hi = max_k;
    int lo = min_k;

    int ans;

    while (lo <= hi){
        int mid = (lo + hi) / 2;

        if (poss(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    printf("%d\n", ans);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &T);

    for (int t=1; t <= T; t++){
        min_k = max_k = 0;

        scanf(" %d", &n);

        for (int i=0; i < n; i++){
            scanf(" %d", &rungs[i]);

            max_k = max(max_k, rungs[i]);

            if (i){
                min_k = max(min_k, rungs[i] - rungs[i - 1]);
            } else {
                min_k = max(min_k, rungs[i]);
            }
        }

        printf("Case %d: ", t);
        solve();
    }
}
