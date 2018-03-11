#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <map>

using namespace std;

const int maxn = 205;

int test_cases;

map < string, int > word_id;
vector <int> adj[maxn];
string words[maxn];

void reset(){
    for (int i=0; i < word_id.size(); i++){
        adj[i].clear();
    }
    word_id.clear();
}

bool word_adj(int a, int b){
    if (words[a].size() != words[b].size()){
        return false;
    }

    int diff = 0;

    for (int i=0; i < words[a].size(); i++){
        if (words[a][i] != words[b][i]){
            diff++;

            if (diff > 1){
                return false;
            }
        }
    }

    return true;
}

void build_adj(){
    for (int i=0; i < word_id.size(); i++){
        for (int j=0; j < word_id.size(); j++){
            if (i == j) continue;

            if (word_adj(i, j)){
                adj[i].push_back(j);
            }
        }
    }
}

void query(int s, int e){
    int dist[maxn] = {};

    queue <int> q;
    q.push(s);

    while (!q.empty()){
        int node = q.front();
        q.pop();

        if (node == e){
            break;
        }

        for (int i=0; i < adj[node].size(); i++){
            int next = adj[node][i];

            if (next == s) continue;

            if (!dist[next]){
                dist[next] = dist[node] + 1;
                q.push(next);
            }
        }
    }

    cout << words[s] << " " << words[e] << " " << dist[e] << endl;
}

void all_input(){
    string input_line, word_a, word_b;
    bool query_mode = true;
    int space_ind = -1;

    bool first_case = true;

    while (getline(cin, input_line)){
        if (input_line.empty()){
            continue;
        } else if (input_line[0] == '*'){
            query_mode = true;
            build_adj();
            continue;
        }

        if (query_mode){
            space_ind = input_line.find(" ");

            if (space_ind != string::npos){
                word_a = input_line.substr(0, space_ind);
                word_b = input_line.substr(space_ind + 1);

                query(word_id[word_a], word_id[word_b]);

                continue;
            } else {
                if (!first_case){
                    cout << endl;
                } else {
                    first_case = false;
                }

                query_mode = false;
                reset();
            }
        }

        if (!query_mode){
            int input_id = word_id.size();
            words[word_id.size()] = input_line;
            word_id.insert({input_line, input_id});
        }
    }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> test_cases;

    all_input();
}
