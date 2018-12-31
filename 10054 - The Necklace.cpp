#include <iostream>
#include <cstdio>
#include <list>
#include <vector>

using namespace std;

const int maxn = 55;

int cases, case_num, n;
vector < pair<int, bool> > adj[maxn];
list <int> soln;

void reset(){
    for (int i=0; i < maxn; i++){
        adj[i].clear();
    }
    soln.clear();
}

void input(){
    scanf("%d", &n);
    for (int i=0; i < n; i++){
        int id1, id2;
        scanf("%d %d", &id1, &id2);
        adj[id1].push_back({id2, true});
        adj[id2].push_back({id1, true});
    }
}

bool possible(){
    for (int i=0; i < maxn; i++){
        if (adj[i].size() % 2) return false;
    }
    return true;
}

void traverse(list<int>::iterator it, int node){
    for (int i=0; i < adj[node].size(); i++){
        pair<int, bool> & next = adj[node][i];

        if (next.second){
            next.second = false;

            for (int j=0; j < adj[next.first].size(); j++){
                pair <int, bool> & back_edge = adj[next.first][j];

                if (back_edge.first == node && back_edge.second){
                    back_edge.second = false;
                    break;
                }
            }

            traverse(soln.insert(it, node), next.first);
        }
    }
}

void solve(){
    printf("Case #%d\n", case_num);
    if (!possible()){
        printf("some beads may be lost\n");
    } else {
        for (int i=0; i < maxn; i++){
            if (!adj[i].empty()){
                traverse(soln.begin(), i);
                break;
            }
        }

        int last_item, first_item;
        last_item = first_item = *soln.begin();

        for (list<int>::iterator it = ++soln.begin(); it != soln.end(); it++){
            printf("%d %d\n", last_item, *it);
            last_item = *it;
        }
        printf("%d %d\n", last_item, first_item);
    }

    if (case_num != cases){
        printf("\n");
    }
}

int main()
{
    ios::sync_with_stdio(false);

    scanf("%d", &cases);

    for (case_num=1; case_num <= cases; case_num++){
        reset();
        input();
        solve();
    }
}
