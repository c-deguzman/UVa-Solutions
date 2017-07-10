#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int n, m, inp;

int main()
{
    while (true){

        scanf(" %d %d", &n, &m);

        if (n == 0 && m == 0){
            break;
        }

        set <int> jack;

        for (int i=0; i != n; i++){
            scanf(" %d", &inp);
            jack.insert(inp);
        }

        int total_count = 0;

        for (int i = 0; i != m; i++){
            scanf(" %d", &inp);

            if (jack.find(inp) != jack.end()){
                total_count++;
            }
        }

        printf("%d\n", total_count);

    }
}
