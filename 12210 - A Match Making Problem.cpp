#include <iostream>
#include <cstdio>

using namespace std;

int n, m, tc;
int young;

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &m) == 2){
        if (n == 0 && m == 0){
            break;
        }

        young = 61;

        for (int i=0; i < n; i++){
            int age;
            scanf(" %d", &age);
            young = min(young, age);
        }

        for (int i=0; i < m; i++){
            int age;
            scanf(" %d", &age);
        }

        printf("Case %d: ", ++tc);
        if (n <= m){
            printf("%d\n", 0);
        } else {
            printf("%d %d\n", n - m, young);
        }
    }
}
