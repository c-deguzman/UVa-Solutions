#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int m, n;

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &m, &n) == 2){

        vector < pair<int, int> > col[10005];

        for (int i=0; i != m; i++){
            int in_row;

            scanf(" %d", &in_row);

            int row_inds[80];

            for (int j=0; j < in_row; j++){
                scanf(" %d", &row_inds[j]);
            }

            for (int j=0; j < in_row; j++){
                int val;
                scanf(" %d", &val);

                col[row_inds[j]].push_back(make_pair(i + 1, val));
            }
        }

        printf("%d %d\n", n, m);

        for (int i=1; i <= n; i++){
            sort(col[i].begin(), col[i].end());

            printf("%d", col[i].size());

            for (int j=0; j < col[i].size(); j++){
                printf(" %d", col[i][j].first);
            }
            printf("\n");

            for (int j=0; j < col[i].size(); j++){

                if (j){
                    printf(" %d", col[i][j].second);
                } else {
                    printf("%d", col[i][j].second);
                }

            }
            printf("\n");
        }
    }
}
