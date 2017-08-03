#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int m, n, k, best;

const int maxn = 105;

vector <int> adj[maxn];

bool black[maxn];
bool ans_store[maxn];

void reset(){
    for (int i=1; i < maxn; i++){
        adj[i].clear();
        black[i] = ans_store[i] = false;
    }
}


void backtrack(int ind, int total){

    if (ind > n){
        if (total > best){
            best = total;
            for (int i=1; i <= n; i++){
                ans_store[i] = black[i];
            }
        }
        return;
    }

    bool can_place = true;

    for (int i=0; i < adj[ind].size() && can_place; i++){
        int next = adj[ind][i];

        if (black[next]){
            can_place = false;
        }
    }

    if (can_place){
        black[ind] = true;
        backtrack(ind + 1, total + 1);
    }

    black[ind] = false;
    backtrack(ind + 1, total);
}

int main()
{
    scanf(" %d", &m);

    while (m--){
        reset();

        scanf(" %d %d", &n, &k);

        while (k--){
            int a, b;
            scanf(" %d %d", &a, &b);

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        backtrack(1, 0);

        printf("%d\n", best);

        for (int i=1; i <= n; i++){
            if (ans_store[i] && --best){
                printf("%d ", i);
            } else if (ans_store[i]){
                printf("%d\n", i);
            }
        }
    }
}
