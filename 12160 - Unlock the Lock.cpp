#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int maxn = 1e4 + 7;
const int mod = 1e4;

int start, goal, num_moves, case_num;
vector <int> moves, dist;

bool init(){
    scanf("%d %d %d", &start, &goal, &num_moves);

    if (start == 0 && goal == 0 && num_moves == 0){
        return false;
    }

    moves.resize(num_moves);
    dist.assign(maxn, -1);

    for (int i=0; i < num_moves; i++){
        scanf("%d", &moves[i]);
    }

    return true;
}

void solve(){
    queue <int> q;
    q.push(start);
    dist[start] = 0;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (int i=0; i < num_moves; i++){
            int next = (curr + moves[i]) % mod;
            if (dist[next] == -1){
                dist[next] = dist[curr] + 1;
                q.push(next);
            }
        }
    }

    printf("Case %d: ", ++case_num);

    if (dist[goal] == -1){
        printf("Permanently Locked\n");
    } else {
        printf("%d\n", dist[goal]);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
