#include <iostream>
#include <cstdio>

using namespace std;

int s, d;

int mask_val(int mask, int max_bits){
    int bits = 0;
    int moved = 0;

    while (moved < max_bits){
        if ((mask >> moved++) & 1){
            bits++;
        }
    }

    return bits * s - (max_bits - bits) * d;
}

bool pass(int mask){
    for (int i=0; i < 12 - 4; i++){
        if (mask_val((mask >> i) , 5) >= 0){
            return false;
        }
    }
    return true;
}


int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %d %d", &s, &d) == 2){

        int best = -1;

        for (int i=0; i < (1 << 12); i++){
            if (!pass(i)){
                continue;
            }

            best = max(best, mask_val(i, 12));
        }

        if (best <= 0){
            printf("Deficit\n");
        } else {
            printf("%d\n", best);
        }
    }
}
