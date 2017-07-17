#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n, q;

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d",&n, &q) == 2){

        vector < pair <int, int> > pos;

        for (int i=0; i < n; i++){
            int inp;
            scanf(" %d", &inp);
            pos.push_back(make_pair(inp, i + 1));
        }

        sort(pos.begin(), pos.end());

        for (int i=0; i < q; i++){
            int val, ith;
            scanf(" %d %d", &ith, &val);


            int hi = n - 1;
            int lo = 0;

            int ans = n;

            while (lo <= hi){
                int mid = (lo + hi) / 2;

                if (pos[mid].first >= val){
                    hi = mid - 1;
                    ans = min(ans, mid);
                } else {
                    lo = mid + 1;
                }
            }

            if (ans == -1 || (ans + ith - 1 >= n) ||
                (pos[ans + ith - 1].first != val)){
                printf("%d\n", 0);
                continue;
            }

            printf("%d\n", pos[ans + ith - 1].second);

        }
    }
}
