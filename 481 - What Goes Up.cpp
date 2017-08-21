#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector <int> min_end, arr, ans;
int inp;

void rev_print(int ind){
    if (ind == -1){
        return;
    }

    rev_print(ans[ind]);
    printf("%d\n", arr[ind]);
}

void binsert(int ind){
    int lo = 0;
    int hi = min_end.size() - 1;

    int res = -1;

    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (inp < arr[min_end[mid]]){
            res = mid;
            hi = mid - 1;
        } else if (inp > arr[min_end[mid]]){
            lo = mid + 1;
        } else {
            return;
        }
    }

    min_end[res] = ind;

    if (res){
        ans[ind] = min_end[res - 1];
    } else {
        ans[ind] = -1;
    }

}

int main()
{
    ios::sync_with_stdio(false);

    for (int i=0;(scanf(" %d", &inp) == 1); i++){
        arr.push_back(inp);
        ans.push_back(-1);

        if (min_end.empty()){
            min_end.push_back(i);
        } else {
            if (inp > arr[min_end.back()]){
                ans[i] = min_end.back();
                min_end.push_back(i);
            } else {
                binsert(i);
            }
        }
    }

    printf("%d\n-\n", min_end.size());

    rev_print(min_end.back());
}
