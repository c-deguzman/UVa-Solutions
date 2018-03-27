#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>

using namespace std;

const int maxn = 200 + 7;

int n, case_num, str_id, concurrent_events;
map <string, int> dict;
string rev[maxn];
bool adj_mat[maxn][maxn];

void reset(){
	dict.clear();
	str_id = 0;
	concurrent_events = 0;
	for (int i=0; i < maxn; i++){
		for (int j=0; j < maxn; j++){
			adj_mat[i][j] = (i == j) ? true : false;
		}
	}
}

bool init(){

	case_num++;
	scanf("%d", &n);

	if (!n) return false;

	reset();

	int events;
	char event1[8], event2[8];

	for (int i=0; i < n; i++){
		scanf("%d", &events);

		vector <string> event_chain;
		vector <int> id_chain;

		for (int j=0; j < events; j++){
			scanf(" %s", &event1);
			event_chain.push_back(event1);

			map<string, int>::iterator it1 = dict.find(event1);

			if (it1 == dict.end()){
				dict[event1] = str_id;
				rev[str_id] = event1;
				id_chain.push_back(str_id);
				str_id++;
			}  else {
				id_chain.push_back(it1->second);
			}
		}

		for (int i=0; i < events - 1; i++){
			int id1 = id_chain[i];
			int id2 = id_chain[i + 1];

			adj_mat[id1][id2] = true;
		}
	}

	scanf("%d", &events);

	for (int i=0; i < events; i++){
		scanf(" %s %s", &event1, &event2);
		int id1 = dict[event1], id2 = dict[event2];

		adj_mat[id1][id2] = true;
	}

	return true;
}

void floyd_warshall(){
	for (int k=0; k < str_id; k++){
		for (int i=0; i < str_id; i++){
			for (int j=0; j < str_id; j++){
                adj_mat[i][j] |= adj_mat[i][k] && adj_mat[k][j];
			}
		}
	}
}

void solve(){
	floyd_warshall();

	vector < pair <int, int> > sol;

	for (int i=0; i < str_id; i++){
		for (int j=i + 1; j < str_id; j++){
			if (!adj_mat[i][j] && !adj_mat[j][i]){
				concurrent_events++;
				sol.push_back({i, j});
			}
		}
	}

	sort(sol.begin(), sol.end());

	printf("Case %d, ", case_num);

	if (!concurrent_events){
        printf("no concurrent events.\n");
	} else {
        printf("%d concurrent events:\n", concurrent_events);

        for (int i=0; i < min(concurrent_events, 2); i++){
            printf("(%s,%s) ", rev[sol[i].first].c_str(), rev[sol[i].second].c_str());
        }
        printf("\n");
	}
}

int main()
{
	ios::sync_with_stdio(false);

	while (init()){
		solve();
	}
}
