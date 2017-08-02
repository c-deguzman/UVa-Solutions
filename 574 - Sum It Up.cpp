#include <iostream>
#include <cstdio>

using namespace std;

int n, t;
int nums[15];
bool found;

bool on_rep(int ind){
    return (!(ind == 0 || (ind > 0 && nums[ind] != nums[ind - 1]) || ind == n));
}

int bit_sum(int mask){
    int total = 0;
    for (int i=0; i < n; i++){
        total += nums[i] * ((mask & (1 << i)) > 0);
    }
    return total;
}

int print_sol(int bitmask){
    bool first = true;
    for (int i=0; i < n; i++){
        if (bitmask & (1 << i)){
            if (first){
                printf("%d", nums[i]);
                first = false;
            } else {
                printf("+%d", nums[i]);
            }
        }
    }
    printf("\n");
}

void solve(int ind, int bitmask){
    int sum = bit_sum(bitmask);

    if (sum == t && ind == n){
        found = true;
        print_sol(bitmask);
        return;
    }

    if (sum > t || ind == n){
        return;
    }

    int base_mask = bitmask, rep = 0;

    while (ind + rep < n && nums[ind] == nums[ind + rep]){
        base_mask |= (1 << ind + rep);
        rep++;
    }

    for (int i=ind + rep; i <= n; i++){

        if (on_rep(i)){
            continue;
        }

        int send_mask = base_mask;

        for (int j=rep; j >= 0; j--){
            solve(i, send_mask);
            send_mask ^= (1 << ind + j - 1);
        }

        break;
    }
}

int main()
{

    ios::sync_with_stdio(false);

    while(scanf(" %d %d", &t, &n) == 2){
        if (t == 0 && n == 0){
            break;
        }

        printf("Sums of %d:\n", t);

        for (int i=0; i < n; i++){
            scanf(" %d", &nums[i]);
        }

        found = false;

        solve(0, 0);

        if (!found){
            printf("NONE\n");
        }
    }
}
