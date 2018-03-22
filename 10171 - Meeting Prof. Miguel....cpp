#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int maxn = 30;

int a, b, m;
int dist_y[maxn][maxn], dist_m[maxn][maxn];

bool init(){
    scanf(" %d", &m);

    if (m == 0) return false;

    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxn; j++){
            dist_y[i][j] = dist_m[i][j] = 1e9;
        }
        dist_y[i][i] = dist_m[i][i] = 0;
    }

    for (int i=0; i < m; i++){
        char age, dir, x_char, y_char;
        int weight;
        scanf(" %c %c %c %c %d", &age, &dir, &x_char, &y_char, &weight);

        int x = x_char - 'A';
        int y = y_char - 'A';

        if (age == 'Y'){
            dist_y[x][y] = min(dist_y[x][y], weight);
            if (dir == 'B'){
                dist_y[y][x] = min(dist_y[y][x], weight);
            }
        } else if (age == 'M'){
            dist_m[x][y] = min(dist_m[x][y], weight);
            if (dir == 'B'){
                dist_m[y][x] = min(dist_m[y][x], weight);
            }
        }
    }

    char a_char, b_char;
    scanf(" %c %c", &a_char, &b_char);

    a = a_char - 'A';
    b = b_char - 'A';

    return true;
}

void floyd_warshall(){
    for (int k=0; k < maxn; k++){
        for (int i=0; i < maxn; i++){
            for (int j=0; j < maxn; j++){
                dist_y[i][j] = min(dist_y[i][j], dist_y[i][k] + dist_y[k][j]);
                dist_m[i][j] = min(dist_m[i][j], dist_m[i][k] + dist_m[k][j]);
            }
        }
    }
}

void solve(){
    floyd_warshall();

    vector <int> cities;
    int cost = 1e9;

    for (int i=0; i < maxn; i++){
        if (cost > dist_y[a][i] + dist_m[b][i]){
            cost = dist_y[a][i] + dist_m[b][i];
            cities.clear();
            cities.push_back(i);
        } else if (cost == dist_y[a][i] + dist_m[b][i]){
            cities.push_back(i);
        }
    }

    if (cost < 1e9){
        printf("%d", cost);
        for (int i=0; i < cities.size(); i++){
            printf(" %c", cities[i] + 'A');
        }
        printf("\n");
    } else {
        printf("You will never meet.\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
