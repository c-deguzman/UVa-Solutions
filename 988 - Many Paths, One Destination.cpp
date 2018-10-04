#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>


using namespace std;

int n;

vector <int> in;
vector < vector <int> > adj;


bool input(){
    int cont = scanf(" %d", &n);

    if (cont != 1) return false;

    if (!adj.empty()){
        printf("\n");
        adj.clear();
    }

    in.assign(n, 0);

    for (int i=0; i < n ; i++){
        vector <int> children;
        int num_children;

        scanf(" %d", &num_children);

        for (int j=0; j < num_children; j++){
            int child;
            scanf(" %d", &child);
            children.push_back(child);
            in[child]++;
        }

        adj.push_back(children);
    }

    return true;
}

vector <int> top_sort(){
    queue <int> q;
    vector <int> ret;

    for (int i=0; i < n; i++){
        if (in[i] == 0){
            q.push(i);
            ret.push_back(i);
        }
    }

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for (int i=0; i < adj[curr].size(); i++){
            int next = adj[curr][i];

            in[next]--;

            if (in[next] == 0){
                q.push(next);
                ret.push_back(next);
            }
        }
    }

    return ret;
}


int solve(){
    vector <int> top_order = top_sort();


    // re-purpose in to keep track of number of possibilities
    in[0] = 1;

    for (int i=0; i < top_order.size(); i++){
        int curr = top_order[i];
        for (int j=0; j < adj[curr].size(); j++){
            int next = adj[curr][j];

            in[next] += in[curr];
        }
    }

    int total = 0;

    for (int i=0; i < n; i++){
        if (adj[i].empty()){
            total += in[i];
        }
    }

    return total;

}


int main()
{
    ios::sync_with_stdio(false);

    while(input()){
        printf("%d\n", solve());
    }
}
