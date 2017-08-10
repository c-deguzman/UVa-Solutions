#include <iostream>
#include <cstdio>

using namespace std;

char mode;
int row, col;
char inp[205 * 205];
char next_move;

int carr_ret;

bool ans[205][205];

bool select(int x, int y){
    return (inp[x * col + y] == '1');
}

bool verdict(int x1, int y1, int x2, int y2){

    int total = 0;

    for (int i=x1; i <= x2; i++){
        for (int j= y1; j <= y2; j++){
            if (select(i, j)){
                total++;
            }
        }
    }

    if (total == 0 || total == (x2 - x1 + 1) * (y2 - y1 + 1)){
        return true;
    } else {
        return false;
    }
}

void solve_b(int x1, int y1, int x2, int y2){
    if (verdict(x1, y1, x2, y2)){
        if (carr_ret == 50){
            printf("\n");
            carr_ret = 0;
        }
        printf("%d", select(x1, y1));

        carr_ret++;
        return;
    }

    if (carr_ret == 50){
        printf("\n");
        carr_ret = 0;
    }

    printf("D");
    carr_ret++;

    int side_x = x2 - x1 + 1;
    int side_y = y2 - y1 + 1;

    int d_x = side_x / 2 - (side_x % 2 == 0);
    int d_y = side_y / 2 - (side_y % 2 == 0);

    if (side_x > 1 && side_y > 1){
        // UL
        solve_b(x1,           y1,           x1 + d_x, y1 + d_y);
        // UR
        solve_b(x1,           y1 + d_y + 1, x1 + d_x, y2);
        // LL
        solve_b(x1 + d_x + 1, y1,           x2,       y1 + d_y);
        // LR
        solve_b(x1 + d_x + 1, y1 + d_y + 1, x2,       y2);
    } else if (side_x == 1){
        // L
        solve_b(x1,           y1,           x2, y1 + d_y);
        // R
        solve_b(x1,           y1 + d_y + 1, x2, y2);
    } else if (side_y == 1){
        // U
        solve_b(x1,           y1,           x1 + d_x, y2);
        // L
        solve_b(x1 + d_x + 1, y1,           x2,       y2);
    }
}

void solve_d(int x1, int y1, int x2, int y2){

    scanf(" %c", &next_move);

    if (next_move == '1' || next_move == '0'){
        for (int i=x1; i <= x2; i++){
            for (int j=y1; j <= y2; j++){
                ans[i][j] = (next_move == '1');
            }
        }
        return;
    }

    int side_x = x2 - x1 + 1;
    int side_y = y2 - y1 + 1;

    int d_x = side_x / 2 - (side_x % 2 == 0);
    int d_y = side_y / 2 - (side_y % 2 == 0);

    if (side_x > 1 && side_y > 1){
        // UL
        solve_d(x1,           y1,           x1 + d_x, y1 + d_y);
        // UR
        solve_d(x1,           y1 + d_y + 1, x1 + d_x, y2);
        // LL
        solve_d(x1 + d_x + 1, y1,           x2,       y1 + d_y);
        // LR
        solve_d(x1 + d_x + 1, y1 + d_y + 1, x2,       y2);
    } else if (side_x == 1){
        // L
        solve_d(x1,           y1,           x2, y1 + d_y);
        // R
        solve_d(x1,           y1 + d_y + 1, x2, y2);
    } else if (side_y == 1){
        // U
        solve_d(x1,           y1,           x1 + d_x, y2);
        // L
        solve_d(x1 + d_x + 1, y1,           x2,       y2);
    }
}

int main()
{
    ios::sync_with_stdio(false);

    while (scanf(" %c", &mode) == 1){

        if (mode == '#'){
            break;
        }

        scanf(" %d %d", &row, &col);

        carr_ret = 0;

        if (mode == 'B'){

            int inp_ind = 0;

            while (true){
                scanf(" %c", &inp[inp_ind++]);
                if (inp_ind == row * col){
                    break;
                }
            }

            printf("D%4d%4d\n", row, col);
            solve_b(0,0, row - 1, col - 1);
        } else {
            printf("B%4d%4d\n", row, col);

            solve_d(0,0, row - 1, col - 1);

            for (int i=0; i < row; i++){
                for (int j=0; j < col; j++){
                    if (carr_ret == 50){
                        printf("\n");
                        carr_ret = 0;
                    }
                    printf("%d", ans[i][j]);
                    carr_ret++;
                }
            }
        }

        printf("\n");
    }
}
