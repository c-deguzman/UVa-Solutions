#include <iostream>
#include <cstdio>

using namespace std;

int ans[25][1005];
int bars[25];

int t,n,p;

void init(){

    scanf(" %d %d", &p, &n);

    for (int i=0; i < n; i++){
        scanf(" %d", &bars[i]);
    }

    for (int i=0; i < n; i++){
        for (int j=0; j <= p; j++){
            ans[i][j] = -1;
        }
    }

}

bool solve(int ind, int len){
    if (len == p){
        return true;
    } else if (len > p || ind == n){
        return false;
    }

    if (ans[ind][len] != -1){
        return ans[ind][len];
    }

    bool poss = false;

    for (int i=ind; i < n && !poss; i++){
        poss |= solve(i + 1, len + bars[i]);
    }

    return ans[ind][len] = poss;


}


int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while(t--){
        init();

        if (solve(0, 0)){
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
