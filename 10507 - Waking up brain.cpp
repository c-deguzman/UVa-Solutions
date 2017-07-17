#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n, m;

    while (scanf(" %d", &n) == 1){
        scanf(" %d", &m);

        vector <int> conn[30];
        bool on[30] = {0};

        char initial[30];
        scanf(" %s", &initial);

        int curr_up = strlen(initial);

        for (int i=0; i != curr_up; i++){
            on[initial[i] - 'A'] = true;
        }

        for (int i = 0; i != m; i++){
            char inp[4];
            scanf(" %s", &inp);

            int a = inp[0] - 'A';
            int b = inp[1] - 'A';

            conn[a].push_back(b);
            conn[b].push_back(a);
        }


        bool change = true;
        int years = 0;

        while (change){

            change = false;

            queue <int> update_list;

            for (int i=0; i <= 'Z' - 'A'; i++){
                int conn_count = 0;

                if (!on[i]){
                    for (int j=0; j != conn[i].size(); j++){
                        if (on[conn[i][j]]){
                            conn_count++;
                        }

                        if (conn_count >= 3){
                            update_list.push(i);
                            break;
                        }
                    }
                }
            }

            if (!update_list.empty()){
                change = true;
                years++;
            }

            while (!update_list.empty()){
                on[update_list.front()] = true;
                update_list.pop();
                curr_up++;
            }
        }

        if (curr_up == n){
            printf("WAKE UP IN, %d, YEARS\n", years);
        } else {
            printf("THIS BRAIN NEVER WAKES UP\n");
        }
    }
}
