#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <queue>

using namespace std;

const int maxn = 27;
const int inf = 1e9;

int cases;

int dist[maxn], in[maxn], v_cost[maxn];
bool pres[maxn];
vector <int> adj[maxn];

void buffer(){
    string rm;
    getline(cin, rm);
    getline(cin, rm);
}

void reset(){
    for (int i=0; i < maxn; i++){
        adj[i].clear();
        pres[i] = false;
    }
}

void parse(string str){
    stringstream ss(str);

    char letter;
    int val;
    string pred = "";

    ss >> letter >> val;

    val *= -1; // max-length problem

    int ind = letter - 'A';

    v_cost[ind] = val;
    pres[ind] = true;

    ss >> pred;
    in[ind] = pred.size();

    dist[ind] = (pred.empty() ? val : inf);

    for (int i=0; i < pred.size(); i++){
        adj[pred[i] - 'A'].push_back(ind);
    }
}

void input(){
    string inp;
    while (getline(cin, inp)){
        if (inp.empty()) return;
        parse(inp);
    }
}

vector <int> top_sort(){
    vector <int> ret;
    queue <int> q;

    for (int i=0; i < maxn; i++){
        if (!in[i] && pres[i]){
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

            if (!in[next]){
                q.push(next);
                ret.push_back(next);
            }
        }
    }

    return ret;
}

int solve(){
    int max_dist = 0;

    vector <int> top_order = top_sort();

    for (int i=0; i < top_order.size(); i++){
        int curr = top_order[i];
        max_dist = min(max_dist, dist[curr]);

        for (int j=0; j < adj[curr].size(); j++){
            int next = adj[curr][j];

            dist[next] = min(dist[next], dist[curr] + v_cost[next]);
        }
    }

    return max_dist * -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> cases;
    buffer();

    while (cases--){
        reset();
        input();
        cout << solve() << endl;

        if (cases > 0){
            cout << endl;
        }

    }

}
