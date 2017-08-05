#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int n, q;
int books[10005];

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d", &n) == 1){
        for (int i=0; i < n; i++){
            scanf(" %d", &books[i]);
        }
        scanf(" %d", &q);

        sort(books, books + n);

        int s = 0;
        int e = n - 1;

        int ans_s = 0, ans_e = 1e9;

        while (s < e){
            if (books[s] + books[e] < q){
                s++;
            } else if (books[s] + books[e] > q){
                e--;
            } else {
                if (books[e] - books[s] < ans_e - ans_s){
                    ans_s = books[s];
                    ans_e = books[e];
                }

                s++;
            }
        }

        printf("Peter should buy books whose prices are %d and %d.\n\n", ans_s, ans_e);
    }
}
