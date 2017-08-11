#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, d, r;

int morn[105], eve[105];

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d %d", &n, &d, &r) == 3){
        if (n == 0 && d == 0 && r == 0){
            break;
        }

        for (int i=0; i < n; i++){
            scanf(" %d", &morn[i]);
        }

        for (int i=0; i < n; i++){
            scanf(" %d", &eve[i]);
        }

        sort(morn, morn + n);
        sort(eve, eve + n);

        int over_time = 0;

        for (int i=0; i < n; i++){
            over_time += max(morn[i] + eve[n - i - 1] - d, 0);
        }

        printf("%d\n", over_time * r);
    }
}
