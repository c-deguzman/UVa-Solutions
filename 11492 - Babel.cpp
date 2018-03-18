#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>

using namespace std;

const int maxm = 2000 + 7, max_str = 55, alpha = 30;

int m, start_lang, end_lang;
int dist[maxm << 1][maxm];
string words[maxm];
map <string, int> trans;
vector <int> dict[maxm << 1];
pair <int, int> options[maxm];

struct State {
    int cost, lang, word;
    State(int cost, int lang, int word): cost{cost}, lang{lang}, word{word} {}
    bool operator<(const State & rhs) const {
        return cost > rhs.cost;
    }
};

void set_row(int row){
    dict[row].clear();
    for (int j=0; j < m; j++){
        dist[row][j] = 1e9;
    }
}

int get_id(char s[]){
    if (trans.find(s) == trans.end()){
        int new_id = trans.size();
        trans[s] = new_id;
        set_row(new_id);
    }
    return trans[s];
}

bool init(){
    scanf("%d", &m);

    if (!m) return false;

    trans.clear();

    char s1[max_str], s2[max_str], s3[max_str];

    scanf(" %s %s", &s1, &s2);

    start_lang = get_id(s1);
    end_lang = get_id(s2);

    for (int i=0; i < m; i++){
        scanf(" %s %s %s", &s1, &s2, &s3);

        int id1 = get_id(s1), id2 = get_id(s2);

        dict[id1].push_back(i);
        dict[id2].push_back(i);

        options[i] = {id1, id2};

        words[i] = s3;
    }

    return true;
}

void solve(){
    priority_queue < State > pq;

    for (int i=0; i < dict[start_lang].size(); i++){
        dist[start_lang][dict[start_lang][i]] = 0;
        pq.push({0, start_lang, dict[start_lang][i]});
    }

    while (!pq.empty()){
        State top = pq.top();
        pq.pop();

        if (dist[top.lang][top.word] < top.cost) continue;

        int next_lang = options[top.word].first != top.lang ? options[top.word].first : options[top.word].second;

        string & word = words[top.word];

        if (dist[next_lang][top.word] > top.cost + word.size()){
            dist[next_lang][top.word] = top.cost + word.size();

            for (int i=0; i < dict[next_lang].size(); i++){
                string & next_word = words[dict[next_lang][i]];
                if (next_word[0] == word[0]) continue;
                pq.push({dist[next_lang][top.word], next_lang, dict[next_lang][i]});
            }
        }
    }

    int low = 1e9;

    for (int i=0; i < dict[end_lang].size(); i++){
        low = min(low, dist[end_lang][dict[end_lang][i]]);
    }

    if (low == 1e9){
        printf("impossivel\n");
    } else {
        printf("%d\n", low);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (init()){
        solve();
    }
}
