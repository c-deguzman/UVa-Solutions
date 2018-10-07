#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 10 + 5;
const int alpha = 26 + 4;
const int mod = 20437;
const int inf = 1e9;

int n, max_level, case_num;
char grid[maxn][maxn];
int dp[maxn][maxn][maxn * maxn], dist[maxn][maxn];
pair <int, int> locs[alpha];

void reset(){
    for (int i=0; i < maxn; i++){
        for (int j=0; j < maxn; j++){
            dist[i][j] = inf;
            for (int k=0; k < maxn * maxn; k++){
                dp[i][j][k] = -1;
            }
        }
    }
}


bool input(){
    scanf(" %d", &n);

    if (n == 0) return false;

    case_num++;
    max_level = 0;

    for (int i=0; i < n; i++){
        scanf(" %s", grid[i]);
        for (int j=0; j < n; j++){
            if ('A' <= grid[i][j] && grid[i][j] <= 'Z'){
                max_level = max(max_level, grid[i][j] - 'A');
                locs[grid[i][j] - 'A'] = {i, j};
            }
        }
    }

    return true;
}

int rec(int y, int x, int steps, int level){
    if (steps < 0) return 0;

    if (grid[y][x] == level + 'A'){
        return 1;
    }

    if (grid[y][x] == '#' || ((grid[y][x] != '.') && (grid[y][x] > level + 'A'))){
        return 0;
    }

    if (dp[y][x][steps] != -1){
        return dp[y][x][steps];
    }

    int total = 0;

    if (y > 0){
        total += rec(y - 1, x, steps - 1, level);
        total %= mod;
    }

    if (y < n - 1){
        total += rec(y + 1, x, steps - 1, level);
        total %= mod;
    }

    if (x > 0){
        total += rec(y, x - 1, steps - 1, level);
        total %= mod;
    }

    if (x < n - 1){
        total += rec(y, x + 1, steps - 1, level);
        total %= mod;
    }

    return dp[y][x][steps] = total;
}

int bfs(int curr_level){
    queue < pair <int, int> > q;

    pair <int, int> start = locs[curr_level - 1], goal = locs[curr_level];
    q.push(start);

    dist[start.first][start.second] = 0;

    while (!q.empty()){
        pair <int, int> curr = q.front();
        q.pop();

        if (curr == goal) break;

        if (curr.second > 0 && dist[curr.first][curr.second - 1] == inf &&
            (grid[curr.first][curr.second - 1] == '.' || grid[curr.first][curr.second - 1] == curr_level + 'A')){
            dist[curr.first][curr.second - 1] = dist[curr.first][curr.second] + 1;
            q.push({curr.first, curr.second - 1});
        }

        if (curr.second < n - 1 && dist[curr.first][curr.second + 1] == inf &&
            (grid[curr.first][curr.second + 1] == '.' || grid[curr.first][curr.second + 1] == curr_level + 'A')){
            dist[curr.first][curr.second + 1] = dist[curr.first][curr.second] + 1;
            q.push({curr.first, curr.second + 1});
        }

        if (curr.first > 0 && dist[curr.first - 1][curr.second] == inf &&
            (grid[curr.first - 1][curr.second] == '.' || grid[curr.first - 1][curr.second] == curr_level + 'A')){
            dist[curr.first - 1][curr.second] = dist[curr.first][curr.second] + 1;
            q.push({curr.first - 1, curr.second});
        }

        if (curr.first < n - 1 && dist[curr.first + 1][curr.second] == inf &&
            (grid[curr.first + 1][curr.second] == '.' || grid[curr.first + 1][curr.second] == curr_level + 'A')){
            dist[curr.first + 1][curr.second] = dist[curr.first][curr.second] + 1;
            q.push({curr.first + 1, curr.second});
        }
    }

    return dist[goal.first][goal.second];

}

void solve(){

    int total_paths = 1, total_steps = 0;

    for (int curr_level = 1; curr_level <= max_level; curr_level++){
        reset();

        grid[locs[curr_level - 1].first][locs[curr_level - 1].second] = '.';

        int min_dist = bfs(curr_level);

        if (min_dist == 1e9){
            total_paths = 0;
            break;
        }

        total_steps += min_dist;

        total_paths *= rec(locs[curr_level - 1].first, locs[curr_level - 1].second,  min_dist, curr_level);
        total_paths %= mod;
    }

    printf("Case %d: ", case_num);

    if (total_paths == 0){
        printf("Impossible\n");
    } else {
        printf("%d %d\n", total_steps, total_paths);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        solve();
    }
}
