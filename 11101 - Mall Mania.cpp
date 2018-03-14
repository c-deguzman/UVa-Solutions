#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 2005;

int num_points;
int dist[maxn][maxn];

void reset(){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxn; j++){
            dist[i][j] = -1;
        }
    }
}

bool next_move(pair <int, int> node, queue < pair <int, int> > & q){

    if (node.first + 1 < maxn){
        if (dist[node.first + 1][node.second] == -2){
            return true;
        } else if (dist[node.first + 1][node.second] == -1){
            dist[node.first + 1][node.second] = dist[node.first][node.second] + 1;
            q.push({node.first + 1, node.second});
        }
    }

    if (node.first - 1 >= 0){
        if (dist[node.first - 1][node.second] == -2){
            return true;
        } else if (dist[node.first - 1][node.second] == -1){
            dist[node.first - 1][node.second] = dist[node.first][node.second] + 1;
            q.push({node.first - 1, node.second});
        }
    }

    if (node.second + 1 < maxn){
        if (dist[node.first][node.second + 1] == -2){
            return true;
        } else if (dist[node.first][node.second + 1] == -1){
            dist[node.first][node.second + 1] = dist[node.first][node.second] + 1;
            q.push({node.first, node.second + 1});
        }
    }

    if (node.second - 1 >= 0){
        if (dist[node.first][node.second - 1] == -2){
            return true;
        } else if (dist[node.first][node.second - 1] == -1){
            dist[node.first][node.second - 1] = dist[node.first][node.second] + 1;
            q.push({node.first, node.second - 1});
        }
    }

    return false;
}

bool solve(){

    scanf("%d", &num_points);

    if (num_points == 0){
        return false;
    }

    reset();

    queue < pair <int, int> > q;

    int r, c;
    for (int i=0; i < num_points; i++){
        scanf("%d %d", &r, &c);
        q.push({r, c});
        dist[r][c] = 0;
    }

    scanf("%d", &num_points);

    for (int i=0; i < num_points; i++){
        scanf("%d %d", &r, &c);
        dist[r][c] = -2;
    }

    while (!q.empty()){
        pair <int, int> curr = q.front();
        q.pop();

        if (next_move(curr, q)){
            printf("%d\n", dist[curr.first][curr.second] + 1);
            break;
        }
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);

    while (solve());
}
