#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 1005;

int r, c;
bool grid[maxn][maxn];
int dist[maxn][maxn];
pair <int, int> start, dest;

bool init(){
    scanf("%d %d", &r, &c);

    if (r == 0 && c == 0){
        return false;
    }

    for (int i=0; i < r; i++){
        for (int j=0; j < c; j++){
            grid[i][j] = false;
            dist[i][j] = 0;
        }
    }

    int rows;
    scanf("%d", &rows);

    for (int i=0; i < rows; i++){
        int row, bombs, col;
        scanf("%d %d", &row, &bombs);

        for (int j=0; j < bombs; j++){
            scanf("%d", &col);
            grid[row][col] = true;
        }
    }

    int x, y;

    scanf("%d %d", &y, &x);
    start = {y, x};

    scanf("%d %d", &y, &x);
    dest = {y, x};

    return true;
}

bool valid_move(int y, int x){
    return (((0 <= y && y < r) && (0 <= x && x < c)) &&
            (!grid[y][x] && !dist[y][x]));
}

void solve(){
    queue < pair <int, int> > q;
    q.push(start);

    while (!q.empty()){
        int y = q.front().first, x = q.front().second;
        q.pop();

        if (valid_move(y + 1, x)){
            q.push({y + 1, x});
            dist[y + 1][x] = dist[y][x] + 1;
        }

        if (valid_move(y - 1, x)){
            q.push({y - 1, x});
            dist[y - 1][x] = dist[y][x] + 1;
        }

        if (valid_move(y, x + 1)){
            q.push({y, x + 1});
            dist[y][x + 1] = dist[y][x] + 1;
        }

        if (valid_move(y, x - 1)){
            q.push({y, x - 1});
            dist[y][x - 1] = dist[y][x] + 1;
        }
    }

    dist[start.first][start.second] = 0;

    printf("%d\n", dist[dest.first][dest.second]);
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
