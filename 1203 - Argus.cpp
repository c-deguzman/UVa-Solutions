#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct task {
    int id;
    int period;
    int curr_time;

    bool operator<(const task &comp) const{
        if (curr_time != comp.curr_time){
            return (curr_time > comp.curr_time);
        } else {
            return (id > comp.id);
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);

    priority_queue<task> tasks;

    while (true){
        char reg[15];
        scanf(" %s", &reg);

        if (reg[0] == '#'){
            break;
        }

        task inp_task;
        scanf(" %d %d", &inp_task.id, &inp_task.period);

        inp_task.curr_time = inp_task.period;

        tasks.push(inp_task);

    }

    int k;
    scanf(" %d", &k);

    for (int i=0; i != k ; i++){
        task query = tasks.top();
        tasks.pop();

        printf("%d\n", query.id, query.curr_time);

        query.curr_time += query.period;

        tasks.push(query);
    }

}
