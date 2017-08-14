#include <iostream>
#include <cstdio>

using namespace std;

int T;
int n, d;

const int maxn = 105;

int lg[maxn], sm[maxn];
int lg_ind, sm_ind;

bool taken[maxn];

void init(){
    scanf(" %d %d", &n, &d);

    for (int i=0; i < maxn; i++){
        lg[i] = sm[i] = -1;
    }

    lg_ind = sm_ind = 0;

    for (int i=0; i < n; i++){
        char sz, dash;
        int dist;

        scanf(" %c %c %d", &sz, &dash, &dist);

        if (sz == 'B'){
            lg[lg_ind++] = dist;
        } else {
            sm[sm_ind++] = dist;
        }
    }
}

int next_step(int max_dist, int curr_pos, bool forw, bool large){
    int st, fin, dir;

    if (forw && large){
        st = 0;
        fin = lg_ind;
        dir = 1;
    } else if (!forw && large) {
        st = lg_ind - 1;
        fin = 0;
        dir = -1;
    } else if (forw && !large) {
        st = sm_ind - 1;
        fin = 0;
        dir = -1;
    } else {
        st = 0;
        fin = sm_ind;
        dir = 1;
    }

    int dist;

    for (int i=st; ((dir > 0) ? (i < fin) : (i >= fin)); i += dir){

        if (large){
            dist = lg[i] - curr_pos;
        } else if (!large && !taken[i]){
            dist = sm[i] - curr_pos;
        } else if (!large && taken[i]){
            continue;
        }

        if (!forw){
            dist *= -1;
        }

        if (0 < dist && dist <= max_dist){
            return i;
        } else if (dist > max_dist && large){
            break;
        } else if (dist <= 0 && !large){
            break;
        }
    }

    return -1;
}

bool poss(int max_dist){

    for (int i=0; i < maxn; i++){
        taken[i] = false;
    }

    int curr_pos = 0;

    //forward
    while (true){

        if (d - curr_pos <= max_dist){
            curr_pos = d;
            break;
        }

        int next_l = next_step(max_dist, curr_pos, true, true);

        if (next_l != -1){
            curr_pos = lg[next_l];
            continue;
        }

        int next_s = next_step(max_dist, curr_pos, true, false);

        if (next_s != -1){
            curr_pos = sm[next_s];
            taken[next_s] = true;
            continue;
        }

        return false;

    }

    //backward
    while (true){

        if (curr_pos  <= max_dist){
            curr_pos = 0;
            break;
        }

        int next_l = next_step(max_dist, curr_pos, false, true);

        if (next_l != -1){
            curr_pos = lg[next_l];
            continue;
        }

        int next_s = next_step(max_dist, curr_pos, false, false);

        if (next_s != -1){
            curr_pos = sm[next_s];
            taken[next_s] = true;
            continue;
        }

        return false;
    }

    return true;

}

int solve(void){
    int lo = 1;
    int hi = d;

    int ans = -1;

    while (lo <= hi){
        int mid = (lo + hi) / 2;

        if (poss(mid)){
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &T);

    for (int t=1; t <= T; t++){
        printf("Case %d: ", t);

        init();
        printf("%d\n", solve());

    }
}
