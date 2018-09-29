#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 121;
const int maxm = 16;
const int inf = 1e9;

char name[15];
int n, m;
int dist[maxn][maxm];

void reset(){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxm; j++){
            dist[i][j] = (i == 0 ? 0 : inf);
        }
    }
}

bool input(){
    int cont = scanf(" %s", &name);

    if (cont != 1) return false;

    reset();

    scanf(" %d %d", &n, &m);

    for (int k=0; k < (n - 1); k++){
        for (int i=1; i <= m; i++){
            for (int j=1; j <= m; j++){
                int travel_cost;
                scanf(" %d", &travel_cost);
                dist[k + 1][j] = min(dist[k + 1][j], dist[k][i] + travel_cost + 2);
            }
        }
    }

    return true;

}

void output(){
    int lo = 1e9;

    for (int i=1; i <= m; i++){
        lo = min(lo, dist[n - 1][i]);
    }

    printf("%s\n%d\n", name, lo);
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        output();
    }
}
