#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>

using namespace std;

const int maxn = 105;

int n, m;

unordered_map <string , int> id;
vector<int> adj_list[maxn];
queue<int> soln;

int in_bound[maxn];
string keys[maxn];

void solve(){
    priority_queue <int> pq;

    for (int i=0; i < n; i++){
        if (!in_bound[i]){
            pq.push(i * -1);
        }
    }

    while (!pq.empty()){
        int curr = pq.top() * -1;
        soln.push(curr);
        pq.pop();

        for (int i=0; i < adj_list[curr].size(); i++){
            int next = adj_list[curr][i];

            in_bound[next]--;

            if (!in_bound[next]){
                pq.push(next * -1);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int case_num = 0;

    while (cin >> n){
        id.clear();

        for (int i=0; i < n; i++){
            cin >> keys[i];
            id.insert({keys[i], i});

            adj_list[i].clear();
        }

        cin >> m;

        for (int i=0; i < m; i++){
            string inp, inp2;
            cin >> inp >> inp2;
            adj_list[id[inp]].push_back(id[inp2]);
            in_bound[id[inp2]]++;
        }

        solve();

        cout << "Case #" << ++case_num << ": Dilbert should drink beverages in this order:";

        while (!soln.empty()){
            cout << " " << keys[soln.front()];
            soln.pop();
        }

        cout << "." << endl << endl;

    }

}

