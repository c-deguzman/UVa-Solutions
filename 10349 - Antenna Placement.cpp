#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int max_h = 42;
const int max_w = 12;

int w, h, towns;
char board[max_h][max_w];
vector < pair <int, int> > adj[max_h][max_w];

bool is_black(int row, int col){
    return (row + col) % 2;
}


void input(){
    scanf(" %d %d", &h, &w);

    for (int i=0; i < h; i++){
        scanf(" %s", &board[i]);
    }

    towns = 0;

    for (int i=0; i < h; i++){
        for (int j=0; j < w; j++){
            adj[i][j].clear();

            if (board[i][j] == 'o') continue;
            towns++;

            if (!is_black(i, j)){
                if (i > 0 && board[i - 1][j] == '*'){
                    adj[i][j].push_back({i - 1, j});
                }

                if (i < h - 1 && board[i + 1][j] == '*'){
                    adj[i][j].push_back({i + 1, j});
                }

                if (j > 0 && board[i][j - 1] == '*'){
                    adj[i][j].push_back({i, j - 1});
                }

                if (j < w - 1 && board[i][j + 1] == '*'){
                    adj[i][j].push_back({i, j + 1});
                }
            }
        }
    }
}

bool claudes_augmenting_flow(int row, int col, vector <int> & black_taken, vector <bool> & vis){
    if (vis[row * w + col]) return false;
    vis[row * w + col] = true;

    for (int i=0; i < adj[row][col].size(); i++){
        pair <int, int> neigh_black = adj[row][col][i];

        int & black_occupy = black_taken[neigh_black.first * w + neigh_black.second];

        if (black_occupy == -1 || claudes_augmenting_flow(black_occupy / w, black_occupy % w, black_taken, vis)){
            black_occupy = row * w + col;
            return true;
        }
    }

    return false;
}


void solve(){
    vector <int> black_taken(max_h * max_w, -1);

    int pairings = 0;

    for (int i=0; i < h; i++){
        for (int j=0; j < w; j++){
            if (!is_black(i, j)){
                vector <bool> vis(max_h * max_w, false);
                pairings += claudes_augmenting_flow(i, j, black_taken, vis);
            }
        }
    }

    printf("%d\n", towns - pairings);

}

int main()
{
    ios::sync_with_stdio(false);

    int test_cases;
    scanf(" %d", &test_cases);

    while(test_cases--){
        input();
        solve();
    }

}
