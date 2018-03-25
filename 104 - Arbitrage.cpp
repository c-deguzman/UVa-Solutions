#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

const int maxn = 22;

int n;
double ex[maxn][maxn][maxn];
int path[maxn][maxn][maxn];
int check[maxn];

bool init(){
    if (scanf("%d", &n) != 1) return false;

    for (int i=0; i < n; i++){
        check[i] = 1e9;
        for (int j=0; j < n; j++){
            path[i][j][0] = i;

            for (int len=1; len < n; len++){
                ex[i][j][len] = -1;
            }

            if (i == j){
                ex[i][j][0] = 1;
                continue;
            }
            scanf("%lf", &ex[i][j][0]);
        }
    }

    return true;
}

void floyd_warshall(){
    // build out path by 1 node each time.
    for (int path_len = 1; path_len < n; path_len++){
        for (int k=0; k < n; k++){
            for (int i=0; i < n; i++){
                for (int j=0; j < n; j++){
                    /*
                        (i -> k) is our previously solved best path of up to <path_len> edges
                        (k -> j) is a direct edge, added on.
                    */
                    double new_value = ex[i][k][path_len - 1] * ex[k][j][0];

                    if (ex[i][j][path_len] < new_value){
                        ex[i][j][path_len] = new_value;
                        path[i][j][path_len] = k;

                        if (i == j && ex[i][j][path_len] > 1.01) check[i] = min(check[i], path_len);
                    }
                }
            }
        }
    }
}

void print_path(int base, int depth){
    stack <int> list_path;

    int next_node = base;
    for (int d = depth; d >= 0; d--){
        list_path.push(path[base][next_node][d]);
        next_node = path[base][next_node][d];
    }

    while (!list_path.empty()){
        printf("%d ", list_path.top() + 1);
        list_path.pop();
    }
    printf("%d\n", base + 1);
}

void solve(){
    floyd_warshall();

    int min_path = 1e9;
    int min_ind = -1;

    for (int i=0; i < n ; i++){
        if (check[i] != 1e9){
            if (min_path > check[i]){
                min_path = check[i];
                min_ind = i;
            }
        }
    }

    if (min_path == 1e9){
        printf("no arbitrage sequence exists\n");
    } else {
        print_path(min_ind, min_path);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }

}
