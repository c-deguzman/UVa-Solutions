#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>

using namespace std;

char inp[1000005], q[105];
int query, q_len, inp_len;

vector <int> lower[30];
vector <int> upper[30];

bool is_upper(char a){
    return (a >= 'A' && a <= 'Z');
}

int try_pos(int pos, int ind){

    if (ind == q_len){
        return pos - 1;
    }

    int find_ind;

    vector <int> *base;

    if (is_upper(q[ind])){
        base = &upper[q[ind] - 'A'];
    } else {
        base = &lower[q[ind] - 'a'];
    }

    find_ind = lower_bound((*base).begin(), (*base).end(), pos) - (*base).begin();

    if (find_ind >= (*base).size()){
        return -1;
    }

    return try_pos((*base)[find_ind] + 1, ind + 1);
}

void solve(void){
    char start = q[0];

    vector <int> *base;

    if (is_upper(start)){
        base = &upper[q[0] - 'A'];
    } else {
        base = &lower[q[0] - 'a'];
    }

    int res = try_pos((*base)[0], 0);

    if (res < 0){
        printf("Not matched\n");
    } else {
        printf("Matched %d %d\n", (*base)[0], res);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %s %d", &inp, &query);

    inp_len = strlen(inp);

    for (int i=0; i < inp_len; i++){
        if (is_upper(inp[i])){
            upper[inp[i] - 'A'].push_back(i);
        } else {
            lower[inp[i] - 'a'].push_back(i);
        }
    }

    while (query--){
        scanf(" %s", &q);

        q_len = strlen(q);

        solve();
    }
}
