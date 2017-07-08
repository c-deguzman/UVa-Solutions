#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 10005;

int arr[maxn];

int curr_len;

void insert_at(int ind){
    for (int i = curr_len + 1; i > ind; i--){
        arr[i] = arr[i - 1];
    }
    arr[ind] = arr[curr_len + 1];
    return;
}

int main()
{
    while (scanf(" %d", &arr[curr_len]) == 1){

        for (int i=0; i != curr_len; i++){
            if (arr[curr_len] > arr[i]){
                insert_at(i);
            }
        }

        curr_len++;

        if (curr_len % 2){
            printf("%d\n", arr[curr_len / 2]);
        } else {
            printf("%d\n", (arr[curr_len / 2 - 1] / 2) + (arr[curr_len /2] / 2) +
                   ((arr[curr_len / 2 - 1] % 2) && (arr[curr_len / 2] % 2)));
        }
    }
}
