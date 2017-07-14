#include <iostream>
#include <cstdio>
#include <unordered_map>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){
        unordered_map <int, int> package;

        int high = 0;
        int package_start = 1;

        int snowflakes;

        scanf(" %d", &snowflakes);

        for (int i=1; i <= snowflakes; i++){
            int flake;
            scanf(" %d", &flake);

            if (package.find(flake) != package.end()){
                package_start = max(package_start, package[flake] + 1);
            }

            package[flake] = i;

            high = max(high, i - package_start + 1);
        }

        printf("%d\n", high);
    }
}
