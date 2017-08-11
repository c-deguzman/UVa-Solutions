#include <iostream>
#include <cstdio>

using namespace std;

int T;
int n;

char grid[105];

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &T);

    for (int t=1; t <= T; t++){
        printf("Case %d: ", t);

        scanf(" %d %s", &n, &grid);

        int sc = 0;

        for (int i=0; i < n; i++){
            if (grid[i] == '.'){
                sc++;
                i += 2;
            }
        }

        printf("%d\n", sc);
    }

}
