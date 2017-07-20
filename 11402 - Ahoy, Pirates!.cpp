#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int test_case;
const int maxn = 1024005;

bool base[maxn];
int st[maxn << 2];
int lazy[maxn << 2];

void st_build(int parent, int left, int right){

    lazy[parent] = 1;

    if (left == right){
        st[parent] = base[left];
        return;
    }

    int mid = (left + right) >> 1;

    st_build((parent << 1), left, mid);
    st_build((parent << 1)|1, mid + 1, right);

    st[parent] = st[(parent << 1)] + st[(parent << 1)|1];
}

void update_lazy_parent(int parent, int left, int right){
    if (lazy[parent] == 1){
        return;
    }

    if (lazy[parent] == -1){
        st[parent] = (right - left + 1) - st[parent];
    } else if (lazy[parent] == 3 || lazy[parent] == -5){
        st[parent] = (right - left + 1);
    } else if (lazy[parent] == 5 || lazy[parent] == -3){
        st[parent] = 0;
    }

    if (left < right){
        if (lazy[parent] == -1){
            lazy[(parent << 1)] *= -1;
            lazy[(parent << 1)|1] *= -1;
        } else {
            lazy[(parent << 1)] = lazy[(parent << 1)|1] = lazy[parent];
        }
    }

    lazy[parent] = 1;
}


void st_lazy_update(int parent, int left, int right, int q_left, int q_right, char mode){

    update_lazy_parent(parent, left, right);

    if (left > q_right || right < q_left){
        return;
    }

    if (left >= q_left && right <= q_right){

        if (mode == 'F'){
            st[parent] = (right - left + 1);
            if (left < right){
                lazy[(parent << 1)] = lazy[(parent << 1)|1] = 3;
            }
        } else if (mode == 'E'){
            st[parent] = 0;
            if (left < right){
                lazy[(parent << 1)] = lazy[(parent << 1)|1] = 5;
            }
        } else if (mode == 'I'){
            st[parent] = (right - left + 1) - st[parent];

            if (left < right){
                lazy[(parent << 1)] *= -1;
                lazy[(parent << 1)|1] *= -1;
            }
        }

        return;
    }

    int mid = (left + right) >> 1;

    st_lazy_update((parent << 1), left, mid, q_left, q_right, mode);
    st_lazy_update((parent << 1)|1, mid + 1, right, q_left, q_right, mode);

    st[parent] = st[(parent << 1)] + st[(parent << 1)|1];
}

int st_lazy_query(int parent, int left, int right, int q_left, int q_right){

    update_lazy_parent(parent, left, right);

    if (left > q_right || right < q_left){
        return 0;
    }

    if (left >= q_left && right <= q_right){
        return st[parent];
    }

    int mid = (left + right) >> 1;

    int res_left = st_lazy_query((parent << 1), left, mid, q_left, q_right);
    int res_right = st_lazy_query((parent << 1)|1, mid + 1, right, q_left, q_right);

    return res_left + res_right;
}


int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &test_case);

    for (int t=1; t <= test_case; t++){

        printf("Case %d:\n", t);

        int m, q, n = 1, q_u = 1;

        scanf(" %d", &m);

        for (int i=0; i != m; i++){
            char pirates[55];
            int rep;

            scanf(" %d", &rep);
            scanf(" %s", &pirates);

            int pir_len = strlen(pirates);

            for (int k=0; k != rep; k++){
                for (int j=0; j != pir_len; j++){
                    base[n] = (pirates[j] == '1');
                    n++;
                }
            }
        }

        n--;

        st_build(1, 1, n);

        scanf(" %d", &q);

        for (int i=0; i != q; i++){
            char mode;
            int l, r;
            scanf(" %c %d %d", &mode, &l, &r);
            l++;
            r++;

            if (mode != 'S'){
                st_lazy_update(1, 1, n, l, r, mode);
            } else {
                printf("Q%d: %d\n", q_u++, st_lazy_query(1, 1, n, l, r));
            }
        }
    }
}
