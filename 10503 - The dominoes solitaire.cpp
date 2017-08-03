#include <iostream>
#include <cstdio>

using namespace std;

struct p{
    int s;
    int e;
};

int n,m;
p first, last;
p ps[16];


bool backtrack(int ind, int bitmask, int last_p){

    if (ind == n && last_p == last.s){
        return true;
    }

    if (ind == n){
        return false;
    }

    bool poss = false;

    for (int i=0; i < m && !poss; i++){
        if (!(bitmask & (1 << i))){
            if (last_p == ps[i].e){
                poss |= backtrack(ind + 1, bitmask | (1 << i), ps[i].s);
            } else if (last_p == ps[i].s){
                poss |= backtrack(ind + 1, bitmask | (1 << i), ps[i].e);
            }
        }
    }

    return poss;
}



int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &n, &m) == 2){

        scanf(" %d %d", &first.s, &first.e);
        scanf(" %d %d", &last.s, &last.e);

        for (int i=0; i < m; i++){
            scanf(" %d %d", &ps[i].s, &ps[i].e);
        }

        if (backtrack(0, 0, first.e)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }

    }
}
