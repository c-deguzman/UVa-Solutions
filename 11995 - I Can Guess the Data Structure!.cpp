#include <iostream>
#include <cstdio>
#include <stack>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int n;

    while (scanf(" %d", &n) == 1){

        stack <int> s;
        queue <int> q;
        priority_queue <int> pq;

        bool s_poss, q_poss, pq_poss;

        s_poss = q_poss = pq_poss = true;

        for (int i=0; i < n; i++){

            int comm, inp;
            scanf(" %d %d", &comm, &inp);

            if (comm == 1){
                if (s_poss){
                    s.push(inp);
                }

                if (q_poss){
                    q.push(inp);
                }

                if (pq_poss){
                    pq.push(inp);
                }
            } else if (comm == 2){
                if (s_poss){
                    if (s.empty() || s.top() != inp){
                        s_poss = false;
                    }

                    if (!s.empty()){
                        s.pop();
                    }
                }

                if (q_poss){
                    if (q.empty() || q.front() != inp){
                        q_poss = false;
                    }
                    if (!q.empty()){
                        q.pop();
                    }
                }

                if (pq_poss){
                    if (pq.empty() || pq.top() != inp){
                        pq_poss = false;
                    }
                    if (!pq.empty()){
                        pq.pop();
                    }
                }
            }
        }

        if (s_poss && !q_poss && !pq_poss){
            printf("stack\n");
        } else if (!s_poss && q_poss && !pq_poss){
            printf("queue\n");
        } else if (!s_poss && !q_poss && pq_poss){
            printf("priority queue\n");
        } else if (!s_poss && !q_poss && !pq_poss){
            printf("impossible\n");
        } else {
            printf("not sure\n");
        }
    }
}
