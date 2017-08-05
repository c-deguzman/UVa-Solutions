#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int tc;

const int n = 5;
const int m = 6;

int k;
char sc1[n][m], sc2[n][m];
bool taken[n][30];

vector <char> pass[n];

int poss_pass[n + 1];

void build(){

    poss_pass[n] = 1;

    for (int i=n - 1; i >= 0; i--){
        pass[i].clear();

        for (int j=0; j < 30; j++){
            taken[i][j] = false;
        }

        for (int j=0; j < m; j++){
            for (int k=0; k < m; k++){
                if (sc1[i][j] == sc2[i][k] && !taken[i][sc1[i][j] - 'A']){
                    pass[i].push_back(sc1[i][j]);
                    taken[i][sc1[i][j] - 'A'] = true;
                }
            }
        }

        poss_pass[i] = poss_pass[i + 1] * pass[i].size();
        sort(pass[i].begin(), pass[i].end());
    }
}


void find_k(){

    int curr = 1;

    for (int i=0; i < n; i++){
        int ind = (k - curr) / poss_pass[i + 1];

        printf("%c", pass[i][ind]);
        curr += ind * poss_pass[i + 1];
    }

    printf("\n");
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &tc);

    while (tc--){

        scanf(" %d", &k);

        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                scanf(" %c", &sc1[j][i]);
            }
        }

        for (int i=0; i < m; i++){
            for (int j=0; j < n; j++){
                scanf(" %c", &sc2[j][i]);
            }
        }

        build();

        if (poss_pass[0] < k){
            printf("NO\n");
            continue;
        }

        find_k();
    }
}
