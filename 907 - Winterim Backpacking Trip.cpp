#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 600 + 5;
const int maxk = 300 + 5;

int n, k;
int dist[maxn];
int max_dist[maxn][maxk];

bool input(){
    int valid = scanf(" %d %d", &n, &k);

    if (valid != 2) return false;

    n++;

    for (int i=0; i < n; i++){
        scanf(" %d", &dist[i]);
        for (int j=0; j <= k; j++){
            max_dist[i][j] = -1;
        }
    }

    return true;
}

int solve(int camp, int breaks){
    if (max_dist[camp][breaks] != -1){
        return max_dist[camp][breaks];
    }

    if (camp == n){
        return 0;
    }

    int best = 1e9;

    if (breaks > 0){
        int sum = 0;
        for (int i=camp; i < n; i++){
            sum += dist[i];
            best = min(best, max(sum,  solve(i + 1, breaks - 1)));
        }
    } else {
        // can convert to prefix sum if it matters
        int sum = 0;
        for (int i=camp; i < n; i++){
            sum += dist[i];
        }
        best = sum;
    }

    return max_dist[camp][breaks] = best;
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        printf("%d\n", solve(0, k));
    }
}
