#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

const int alpha = ('Z' - 'A' + 1), comps = 10, end_pts = 2;
const int maxn = alpha + comps + end_pts + 2, max_str = 50;

const int SOURCE = 0, SINK = maxn - 1;

int total_users;
vector < pair <int, int> > adj[maxn];

void reset(){
    total_users = 0;

    for (int i=0; i < maxn; i++){
        adj[i].clear();
    }

    for (int i=0; i < comps; i++){
        int comp_id = i + alpha + 1;
        adj[comp_id].push_back({1, SINK});
        adj[SINK].push_back({0, comp_id});
    }
}

void parse_line(char input_line[]){
    int app = input_line[0] - 'A' + 1;
    int users = input_line[1] - '0';

    total_users += users;

    adj[SOURCE].push_back({users, app});
    adj[SOURCE].push_back({0, app});

    for (int i = 3; input_line[i] != ';'; i++){
        int comp_id = (input_line[i] - '0') + alpha + 1;
        adj[app].push_back({1, comp_id});
        adj[comp_id].push_back({0, app});
    }
}

bool input(){
    int line_ind, lines = 0;
    reset();

    do {
        lines++;
        line_ind = 0;
        char full_line[max_str] = {0};
        while (scanf("%c", &full_line[line_ind]) == 1 && full_line[line_ind] != '\n'){
            line_ind++;
        }

        if (line_ind > 2){
            parse_line(full_line);
        }
    } while (line_ind > 0);

    return lines > 1;
}

void augment_node(int from, int to, int value){
    for (int i=0; i < adj[from].size(); i++){
        int next_node = adj[from][i].second, curr_cap = adj[from][i].first;

        if (next_node != to) continue;

        adj[from][i] = {curr_cap + value, to};
        break;
    }
    return;
}

void augment(vector <int> & parent){
    int curr = SINK;
    while (parent[curr] != -1){
        augment_node(parent[curr], curr, -1);
        augment_node(curr, parent[curr], 1);
        curr = parent[curr];
    }
}

void edmonds_karp(){
    bool flow_poss = true;

    while (flow_poss){
        flow_poss = false;

        vector <bool> visit(maxn, false);
        vector <int> p(maxn, -1);

        queue <int> q;

        q.push(SOURCE);

        while (!q.empty()){
            int node = q.front();
            q.pop();

            visit[node] = true;

            if (node == SINK){
                augment(p);
                flow_poss = true;
                break;
            }

            for (int i=0; i < adj[node].size(); i++){
                int next_node = adj[node][i].second, rem_flow = adj[node][i].first;

                if (!visit[next_node] && rem_flow > 0){
                    q.push(next_node);
                    p[next_node] = node;
                }
            }
        }
    }
}

char solve_app(int node){
    for (int i=0; i < adj[node].size(); i++){
        int flow = adj[node][i].first, next_node = adj[node][i].second;

        if (flow > 0 && 0 < next_node && next_node <= alpha){
            return (next_node - 1) + 'A';
        }
    }

}

void print_solution(){
    int total_sat = 0;

    for (int i=0; i < adj[SINK].size(); i++){
        total_sat += adj[SINK][i].first;
    }

    if (total_sat != total_users){
        printf("!\n");
        return;
    }

    char alloc_apps[comps] = {0};

    for (int i=0; i < adj[SINK].size(); i++){
        int flow = adj[SINK][i].first, comp = adj[SINK][i].second - (alpha + 1);
        if (flow > 0){
            alloc_apps[comp] = solve_app(comp + (alpha + 1));
        }
    }

    for (int i=0; i < comps; i++){
        if (alloc_apps[i] == 0){
            printf("_");
        } else {
            printf("%c", alloc_apps[i]);
        }
    }
    printf("\n");
}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        edmonds_karp();
        print_solution();
    }
}
