#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <cmath>

using namespace std;

vector < array<int, 8> > ans;
array<int, 8> row, inp;
int tc;

bool place(int r, int c){
    for (int i=0; i < c; i++){
        if (row[i] == r || (abs(row[i] - r) == abs(i - c))){
            return false;
        }
    }
    return true;
}

void build(int c){
    if (c == 8){
        ans.push_back(row);
    }

    for (int i=0; i < 8; i++){
        if (place(i, c)){
            row[c] = i;
            build(c + 1);
        }
    }
}

int diff(int ind){

    int total = 0;

    for (int i=0; i < 8; i++){
        total += (ans[ind][i] + 1 != inp[i]);
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);

    build(0);

    while (scanf(" %d", &inp[0]) == 1){

        for (int i=1; i < 8; i++){
            scanf(" %d", &inp[i]);
        }

        int best = 1e9;

        for (int i=0; i < ans.size(); i++){
            best = min(best, diff(i));
        }

        printf("Case %d: %d\n", ++tc, best);
    }
}
