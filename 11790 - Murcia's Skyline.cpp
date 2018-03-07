#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n, test_case;
vector < pair <int, int> > asc, desc;
vector < int > h, w;

void init(){
    scanf("%d", &n);
    asc.clear();
    desc.clear();

    h.assign(n, 0);
    w.assign(n, 0);

    int inp;

    for (int i=0; i < n; i++){
        scanf("%d", &h[i]);
    }

    for (int i=0; i < n; i++){
        scanf("%d", &w[i]);
    }
}

void solve(){
    asc.push_back({h[0], w[0]});
    desc.push_back({h[0], w[0]});

    for (int i=1; i < n; i++){

        // Solve ascending
        int best_pre = 0;

        for (int j = i - 1; j >= 0; j--){
            if (h[i] > h[j]){
                best_pre = max(best_pre, asc[j].second);
            }
        }

        asc.push_back({h[i], w[i] + best_pre});

        // Solve descending
        best_pre = 0;

        for (int j = i - 1; j >= 0; j--){
            if (h[i] < h[j]){
                best_pre = max(best_pre, desc[j].second);
            }
        }

        desc.push_back({h[i], w[i] + best_pre});
    }
}

void print_solution(int case_num){
    int max_asc = -1, max_desc = -1;

    for (int i=0; i < n; i++){
        max_asc = max(max_asc, asc[i].second);
        max_desc = max(max_desc, desc[i].second);
    }

    if (max_asc >= max_desc){
        printf("Case %d. Increasing (%d). Decreasing (%d).\n", case_num, max_asc, max_desc);
    } else {
        printf("Case %d. Decreasing (%d). Increasing (%d).\n", case_num, max_desc, max_asc);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &test_case);

    for (int t_case=1; t_case <= test_case; t_case++){
        init();
        solve();
        print_solution(t_case);
    }

}
