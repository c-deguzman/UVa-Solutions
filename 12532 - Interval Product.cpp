#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 100005;

int n, k;
int inp_arr[maxn];
int seg_tree[maxn << 2];

char command;
int inp1, inp2;

void build(int parent, int left, int right){
    if (left == right){
        seg_tree[parent] = inp_arr[left];
        return;
    }

    int mid = ((left + right) >> 1);

    build((parent << 1), left, mid);
    build((parent << 1)|1, mid + 1, right);

    seg_tree[parent] = seg_tree[parent << 1] * seg_tree[(parent << 1)|1];
}

int query(int parent, int left, int right, int q_left, int q_right){
    if (left > q_right || right < q_left){
        return 1;
    }

    if (left >= q_left && right <= q_right){
        return seg_tree[parent];
    }

    int mid = ((left + right) >> 1);

    int res_left = query((parent << 1), left, mid, q_left, q_right);

    if (!res_left){
        return res_left;
    }

    int res_right = query((parent << 1)|1, mid + 1, right, q_left, q_right);

    return res_left * res_right;
}

void update(int parent, int left, int right, int ind, int val){
    if (left == right){
        seg_tree[parent] = inp_arr[ind] = val;
        return;
    }

    int mid = (left + right) >> 1;

    if (left <= ind && ind <= mid){
        update((parent << 1), left, mid, ind, val);
    } else if ((mid + 1) <= ind && ind <= right){
        update((parent << 1)|1, mid + 1, right, ind, val);
    }

    seg_tree[parent] = seg_tree[(parent << 1)] * seg_tree[(parent << 1)|1];
}

int val_suppress(int num){
    if (!num){
        return num;
    }

    return (1 - 2 * (num < 0));
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &k) == 2){

        for (int i=1; i <= n; i++){
            scanf(" %d", &inp_arr[i]);
            inp_arr[i] = val_suppress(inp_arr[i]);
        }

        build(1, 1, n);

        for (int i=0; i < k; i++){

            scanf(" %c %d %d", &command, &inp1, &inp2);

            if (command == 'C'){

                int now = val_suppress(inp2);

                if (inp_arr[inp1] != now){
                    update(1, 1, n, inp1, now);
                }

            } else {
                int res = query(1, 1, n, inp1, inp2);

                if (res > 0){
                    printf("+");
                } else if (res < 0){
                    printf("-");
                } else {
                    printf("%d", res);
                }
            }
        }
        printf("\n");
    }
}
