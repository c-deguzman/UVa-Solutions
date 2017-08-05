#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string nums[10] = { "YYYYYYN",
                    "NYYNNNN",
                    "YYNYYNY",
                    "YYYYNNY",
                    "NYYNNYY",
                    "YNYYNYY",
                    "YNYYYYY",
                    "YYYNNNN",
                    "YYYYYYY",
                    "YYYYNYY"};

int n;
char inp[12][12];

bool burn[10];

bool attempt_next(int num, int comp){
    for (int i=0; i < nums[num].size(); i++){
        if (inp[comp][i] == 'Y' && burn[i]){
            return false;
        }

        if (inp[comp][i] != nums[num][i]){
            if (nums[num][i] == 'Y'){
                burn[i] = true;
            } else if (nums[num][i] == 'N'){
                return false;
            }
        }
    }

    return true;
}

bool attempt_first(int num){

    for (int i=0; i < nums[num].size(); i++){
        if (inp[0][i] != nums[num][i]){
            if (nums[num][i] == 'Y'){
                burn[i] = true;
            } else if (nums[num][i] == 'N'){
                return false;
            }
        }
    }

    bool poss = true;

    for (int i=1; i < n && poss; i++){
        poss &= attempt_next(num - i, i);
    }

    return poss;
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &n) == 1){

        if (n == 0){
            break;
        }

        for (int i=0; i < n; i++){
            scanf(" %s", &inp[i]);
        }

        bool solved = false;

        for (int i=9; i >= n - 1 && !solved; i--){
            memset(burn, 0, sizeof(burn));

            solved |= attempt_first(i);
        }

        if (solved){
            printf("MATCH\n");
        } else {
            printf("MISMATCH\n");
        }

    }
}
