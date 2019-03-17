#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int max_n = 505;


int bolts, nuts, cases;
vector <int> adj[max_n];
int nut_taken[max_n];

void input(){
    scanf(" %d %d", &bolts, &nuts);

    for (int i=0; i < nuts; i++){
        nut_taken[i] = -1;
    }

    for (int i=0; i < bolts; i++){
        adj[i].clear();
        for (int j=0; j < nuts; j++){
            int fits;
            scanf(" %d", &fits);
            if (fits){
                adj[i].push_back(j);
            }
        }
    }


}

bool claudes_augmenting_flow(int curr_bolt, vector <bool> & vis){
    if (vis[curr_bolt]) return false;
    vis[curr_bolt] = true;

    for (int i=0; i < adj[curr_bolt].size(); i++){
        int curr_nut = adj[curr_bolt][i];
        if (nut_taken[curr_nut] == -1 || claudes_augmenting_flow(nut_taken[curr_nut], vis)){
           nut_taken[curr_nut] = curr_bolt;
           return true;
        }
    }
    return false;
}


// Maximum Cardinality Bipartite Matching
void solve(){
    int total_matching = 0;

    for (int i=0; i < bolts; i++){
        vector <bool> vis(bolts, false);
        total_matching += claudes_augmenting_flow(i, vis);
    }

    printf("%d", total_matching);
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &cases);

    for (int c=1; c <= cases; c++){
        input();
        printf("Case %d: a maximum of ", c);
        solve();
        printf(" nuts and bolts can be fitted together\n");
    }


}
