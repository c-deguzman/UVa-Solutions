#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 107;

int u, v, case_num;
int dist[maxn][maxn];

bool init(){

    case_num++;

    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxn; j++){
            dist[i][j] = 1e9;
        }
        dist[i][i] = 0;
    }

    int input_round = 0;
    do {
        scanf("%d %d", &u, &v);
        dist[u][v] = 1;
        input_round++;
    } while (u || v);

    return input_round > 1;
}

void floyd_warshall(){
    for (int k = 1; k < maxn; k++){
        for (int i = 1; i < maxn; i++){
            for (int j=1; j < maxn; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

void solve(){
    double connects = 0;
    double total = 0;

    floyd_warshall();

    for (int i=1; i < maxn; i++){
        for (int j=1; j < maxn; j++){
            if (i == j) continue;

            if (dist[i][j] != 1e9){
                connects++;
                total += (double) dist[i][j];
            }
        }
    }

    printf("Case %d: average length between pages = %.3f clicks\n", case_num, total / connects);
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
