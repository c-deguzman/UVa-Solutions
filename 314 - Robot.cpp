#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int maxn = 57;
const int max_straight = 3;

struct State{
    int r, c, d;
};

int n, m;
bool grid[maxn][maxn];
int dist[maxn][maxn][4];
State parent[maxn][maxn][4];

int br, bc, er, ec, bd;

bool init(){
    scanf("%d %d", &n, &m);

    if (n == 0 && m == 0){
        return false;
    }

    for (int i=0; i < n; i++){
        for (int j=0; j < m; j++){
            grid[i][j] = false;
            scanf("%d", &grid[i][j]);

            for (int k=0; k < 4; k++){
               dist[i][j][k] = -1;
            }
        }
    }

    scanf("%d %d %d %d", &br, &bc, &er, &ec);

    char direction[20];
    scanf(" %s", &direction);

    if (direction[0] == 'n'){
        bd = 0;
    } else if (direction[0] == 'e'){
        bd = 1;
    } else if (direction[0] == 's'){
        bd = 2;
    } else {
        bd = 3;
    }

    return true;
}

State move_straight(int r, int c, int d, int amt){
    int next_r = r, next_c = c;

    if (d == 0){
        next_r -= amt;
    } else if (d == 1){
        next_c += amt;
    } else if (d == 2){
        next_r += amt;
    } else if (d == 3){
        next_c -= amt;
    }

    return {next_r, next_c, d};
}

bool can_move_straight(State next_state){
    if ((next_state.r < 1 || next_state.c < 1) || (next_state.r >= n || next_state.c >= m)){
        return false;
    }

    return !(grid[next_state.r][next_state.c] ||
             grid[next_state.r][next_state.c - 1] ||
             grid[next_state.r - 1][next_state.c] ||
             grid[next_state.r - 1][next_state.c - 1]);
}

queue <State> move_straight(int r, int c, int d){
    queue <State> q;

    for (int i=max_straight; i >= 1; i--){
        if (can_move_straight(move_straight(r, c, d, i))){
            q.push(move_straight(r, c, d, i));
        } else {
            while (!q.empty()){
                q.pop();
            }
        }
    }

    return q;
}

queue <State> poss_moves(State node){
    int r = node.r, c = node.c, d = node.d;
    queue <State> valids, straight;

    valids.push({r, c, (d - 1 + 4) % 4});
    valids.push({r, c, (d + 1 + 4) % 4});

    straight = move_straight(r, c, d);

    while (!straight.empty()){
        valids.push(straight.front());
        straight.pop();
    }

    return valids;
}


void solve(){
    queue <State> q;
    q.push({br, bc, bd});

    dist[br][bc][bd] = 0;

    while (!q.empty()){
        State curr = q.front();
        q.pop();

        queue <State> moves = poss_moves(curr);

        while (!moves.empty()){
            State next = moves.front();
            moves.pop();

            if (dist[next.r][next.c][next.d] == -1){
                dist[next.r][next.c][next.d] = dist[curr.r][curr.c][curr.d] + 1;
                parent[next.r][next.c][next.d] = curr;
                q.push(next);
            }
        }
    }

    int lo = 90000;

    for (int i=0; i < 4; i++){
        lo = min(dist[er][ec][i], lo);
    }

    printf("%d\n", lo);
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }

}
