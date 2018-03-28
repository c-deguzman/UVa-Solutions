#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

const int maxn = 50 + 7;

int n, m, case_num;
int dist[maxn][maxn];
map <string, int> dict;

bool init(){
    scanf("%d %d", &n, &m);

    if (n == 0 && m == 0) return false;

    case_num++;

    dict.clear();
    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            dist[i][j] = (i == j) ? 0 : 1e9;
        }
    }

    char name1[50], name2[50];

    for (int i=0; i < m; i++){
        scanf(" %s %s", &name1, &name2);

        if (!dict[name1]){
            dict[name1] = dict.size();
        }

        if (!dict[name2]){
            dict[name2] = dict.size();
        }

        int id1 = dict[name1] - 1;
        int id2 = dict[name2] - 1;

        dist[id1][id2] = 1;
        dist[id2][id1] = 1;
    }

    return true;
}

void floyd_warshall(){
    for (int k=0; k < n; k++){
        for (int i=0; i < n; i++){
            for (int j=0; j < n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}

int max_dist(){
    int high = -1;

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            high = max(high, dist[i][j]);
        }
    }

    return high;
}

void solve(){
    floyd_warshall();
    int separation = max_dist();

    printf("Network %d: ", case_num);

    if (separation >= 1e9){
        printf("DISCONNECTED\n");
    } else {
        printf("%d\n", separation);
    }

    printf("\n");
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
