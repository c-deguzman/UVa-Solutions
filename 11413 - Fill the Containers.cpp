#include <iostream>
#include <cstdio>

using namespace std;

int n, m;
long long total;
long long max_ele;
int vess[1005];

bool poss(long long maximum){

    int curr_count = 0;
    int curr_fill = 0;

    for (int i=0; i < n; i++){
        curr_fill += vess[i];

        if (curr_fill > maximum){
            curr_count++;
            curr_fill = vess[i];
        }

        if (curr_count == m){
            return false;
        }
    }

    return true;
}

void solve(void){
    long long hi = total;
    long long lo = max_ele;

    long long ans;

    while (lo <= hi){
        long long mid = (hi + lo) / 2;

        if (poss(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    printf("%lld\n", ans);
}

int main()
{
    ios::sync_with_stdio(false);

    while(scanf(" %d %d", &n, &m) == 2){
        total = max_ele = 0;

        for (int i=0; i < n; i++){
            scanf(" %d", &vess[i]);
            total += (long long) vess[i];
            max_ele = max(max_ele, (long long) vess[i]);
        }

        solve();

    }
}
