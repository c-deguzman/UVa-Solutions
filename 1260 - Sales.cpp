#include <iostream>
#include <cstdio>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){
        int n, arr[1005];
        scanf(" %d", &n);

        int total = 0;

        for (int i=0; i < n; i++){
            scanf(" %d", &arr[i]);
            for (int j=0; j < i; j++){
                if (arr[j] <= arr[i]){
                    total++;
                }
            }
        }

        printf("%d\n", total);
    }
}
