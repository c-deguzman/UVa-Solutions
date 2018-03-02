#include <iostream>
#include <cstdio>
#include <set>
#include <stack>
#include <map>

using namespace std;

const int maxn = 25 + 7;

int n, m, disc_time, case_num;

map < string , int > names;
string rev_map[maxn];

stack <int> tarjan_stack;
set <int> adj[maxn];
int disc[maxn], low[maxn];
bool vis[maxn], on_stack[maxn];

bool init(){
    scanf("%d %d", &n, &m);

    if (n == 0 && m == 0){
        return false;
    }

    names.clear();
    disc_time = 0;

    for (int i=0; i <= n; i++){
        adj[i].clear();
        vis[i] = false;
        rev_map[i] = "";
    }

    int total_names = 0;

    for (int i=0; i < m; i++){
        int from, to;
        char from_cstr[26], to_cstr[26];
        scanf(" %s %s", &from_cstr, &to_cstr);

        string from_str(from_cstr), to_str(to_cstr);

        if (!names[from_str]){
            names[from_str] = ++total_names;
            rev_map[total_names] = from_str;
        }

        if (!names[to_str]){
            names[to_str] = ++total_names;
            rev_map[total_names] = to_str;
        }

        adj[names[from_str]].insert(names[to_str]);
    }

    return true;
}


void tarjan(int node){
    vis[node] = on_stack[node] = true;
    disc[node] = low[node] = disc_time++;

    tarjan_stack.push(node);

    for (set<int>::iterator it = adj[node].begin(); it != adj[node].end(); it++){
        int next = *it;

        if (!vis[next]){
            tarjan(next);
            low[node] = min(low[node], low[next]);
        } else if (on_stack[next]){
            low[node] = min(low[node], disc[next]);
        }
    }

    if (disc[node] == low[node]){
        int scc_mem = -1;

        while (scc_mem != node){
            scc_mem = tarjan_stack.top();
            tarjan_stack.pop();
            on_stack[scc_mem] = false;

            printf("%s", rev_map[scc_mem].c_str());

            if (scc_mem != node){
                printf(", ");
            } else {
                printf("\n");
            }

        }
    }
}

void solve(){
    case_num++;

    if (case_num > 1){
        printf("\n");
    }

    printf("Calling circles for data set %d:\n", case_num);

    if (m > 0){
       for (int i=1; i <= n; i++){
            if (!vis[i]){
                tarjan(i);
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
