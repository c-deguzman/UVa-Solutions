#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 100005;
const int st_maxn = 4 * maxn;

vector < pair <int, int> > base;

int fast_select[maxn];
int st[st_maxn];

int base_selection(int ind){
    return fast_select[ind];
}


int freq_calc(int ind, int left, int right){

    int total_occ = base[ind].second - base[ind].first + 1;

    if (base[ind].first < left){
        total_occ -= (left - base[ind].first);
    }

    if (base[ind].second > right){
        total_occ -= (base[ind].second - right);
    }

    return total_occ;
}

void build(int parent, int left, int right){
    if (left == right){
        st[parent] = base_selection(left);
        return;
    }

    build((parent << 1), left, (left + right) / 2);
    build((parent << 1) + 1, (left + right) / 2 + 1, right);

    int mid_left = base_selection((left + right) / 2);
    int mid_right = base_selection((left + right) / 2 + 1);

    int freq_left = freq_calc(st[(parent << 1)], left, right);
    int freq_right = freq_calc(st[(parent << 1) + 1], left, right);

    if (freq_left > freq_right){
        st[parent] = st[(parent << 1)];
    } else {
        st[parent] = st[(parent << 1) + 1];
    }

    if (mid_left == mid_right){
        int freq_mid = freq_calc(mid_left, left, right);

        if (freq_mid > freq_left && freq_mid > freq_right){
            st[parent] = mid_left;
        }
    }

    return;
}

int query(int parent, int left, int right, int q_left, int q_right){
    if (q_left > right || q_right < left){
        return 0;
    }

    if (left >= q_left && right <= q_right){
        return st[parent];
    }

    int qe_left = query((parent << 1), left, (left + right) / 2, q_left, q_right);
    int qe_right = query((parent << 1) + 1, (left + right) / 2 + 1, right, q_left, q_right);

    int ans;

    int freq_left = freq_calc(qe_left, q_left, q_right);
    int freq_right = freq_calc(qe_right, q_left, q_right);

    int mid_left = base_selection((left + right) / 2);
    int mid_right = base_selection((left + right) / 2 + 1);


    if (freq_left > freq_right){
        ans = qe_left;
    } else {
        ans = qe_right;
    }

    if (mid_left == mid_right){
        int freq_mid = freq_calc(mid_left, q_left, q_right);

        if (freq_mid > freq_left && freq_mid > freq_right){
            ans = mid_left;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    int n, m;

    while (scanf(" %d %d", &n, &m) == 2){

        base.clear();

        int last_val;
        int last_start = 0;

        int curr_it = 0;

        fast_select[1] = curr_it;

        scanf(" %d", &last_val);

        for (int i=1; i != n; i++){
            int curr_val;
            scanf(" %d", &curr_val);

            if (curr_val != last_val){
                base.push_back(make_pair(last_start + 1, i));
                last_start = i;
                curr_it++;
            }

            fast_select[i + 1] = curr_it;
            last_val = curr_val;
        }

        base.push_back(make_pair(last_start + 1, n));

        build(1, 1, n);

        for (int i=0; i < m; i++){
            int l, r;
            scanf(" %d %d", &l, &r);
            printf("%d\n", freq_calc(query(1, 1, n, l, r), l, r));
        }
    }
}
