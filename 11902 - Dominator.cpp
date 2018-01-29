#include <iostream>
#include <cstdio>

using namespace std;

const int maxn = 105;
int n, goal = 0, test_cases, black_out = -1;

bool vis[maxn];
bool adj_mat[maxn][maxn];
bool dom_mat[maxn][maxn];

bool dfs(int node){

    if (node == black_out){
        return false;
    } else if (node == goal){
        return true;
    }

    vis[node] = true;

    for (int i=0; i < n; i++){
        if (adj_mat[node][i] && !vis[i]){
            if (dfs(i)){
                return true;
            }
        }
    }

    return false;
}

bool start_search(int goal_node){

    goal = goal_node;

    for (int i=0; i < n; i++){
        vis[i] = false;
    }

    return dfs(0);
}

void read_input(){
    scanf("%d", &n);

    for (int i=0; i < n; i++){
        for (int j=0; j < n; j++){
            scanf("%d", &adj_mat[i][j]);
            dom_mat[i][j] = false;
        }
    }
}

void build_dom_mat(){
    for (int i=0; i < n; i++){
        bool can_visit = start_search(i);

        if (!can_visit){
            continue;
        }

        for (int j=0; j < n; j++){
            black_out = j;

            bool can_still_visit = start_search(i);
            dom_mat[j][i] = !can_still_visit;
        }

        black_out = -1;
    }
}

void print_horz(){
    printf("+");
    for (int i=0; i < 2 * n - 1; i++){
        printf("-");
    }
    printf("+\n");
}

void print_res(){
    print_horz();

    for (int i=0; i < n; i++){
        printf("|");
        for (int j=0; j < n; j++){
            printf("%c|", dom_mat[i][j] ? 'Y' : 'N');
        }
        printf("\n");
        print_horz();
    }
}

int main()
{
    scanf("%d", &test_cases);

    for (int i=1; i <= test_cases; i++){

        printf("Case %d:\n", i);

        read_input();
        build_dom_mat();
        print_res();
    }
}

