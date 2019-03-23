#include <iostream>
#include <cstdio>

using namespace std;

int r, n, case_num;

bool input(){
    scanf(" %d %d", &r, &n);
    case_num++;
    return (r || n);
}

void solve(){
    printf("Case %d: ", case_num);

    int soln = r / n + (r  % n ? 1 : 0) - 1;

    if (soln <= 26){
        printf("%d\n", soln);
    } else {
        printf("impossible\n");
    }

}

int main()
{
    ios::sync_with_stdio(false);

    while (input()){
        solve();
    }
}
