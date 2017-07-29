#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int t, n;
int grid[30];

int dist(int orig, int dest){
    int orig_x = orig / 5;
    int orig_y = orig % 5;

    int dest_x = dest / 5;
    int dest_y = dest % 5;

    return grid[orig] * ((int)abs(orig_x - dest_x) + (int) abs(orig_y - dest_y));
}

void solve(){

    int best = 1e9;
    int best_rec[] = {0,0,0,0,0};

    for (int a=0; a < 25 - 4; a++){
        for (int b = a + 1; b < 25 - 3; b++){
            for (int c = b + 1; c < 25 - 2; c++){
                for (int d = c + 1; d < 25 - 1; d++){
                    for (int e = d + 1; e < 25; e++){

                        int local_score = 0;

                        for (int i=0; i < 25; i++){
                            int best_dist = 1e9;

                            best_dist = min(best_dist, dist(i, a));
                            best_dist = min(best_dist, dist(i, b));
                            best_dist = min(best_dist, dist(i, c));
                            best_dist = min(best_dist, dist(i, d));
                            best_dist = min(best_dist, dist(i, e));

                            local_score += best_dist;
                        }

                        if (local_score < best){
                            best = local_score;
                            best_rec[0] = a;
                            best_rec[1] = b;
                            best_rec[2] = c;
                            best_rec[3] = d;
                            best_rec[4] = e;
                        }

                    }
                }
            }
        }
    }


    for (int i=0; i < 5; i++){
        printf("%d", best_rec[i]);

        if (i < 4){
            printf(" ");
        }
    }
    printf("\n");

}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){
        scanf(" %d", &n);

        for (int i=0; i < 30; i++){
            grid[i] = 0;
        }

        for (int i=0; i < n; i++){
            int r, c, v;
            scanf(" %d %d %d", &r, &c, &v);
            grid[r * 5 + c] = v;
        }

        solve();

    }
}
