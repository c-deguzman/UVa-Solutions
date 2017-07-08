#include <iostream>
#include <cstdio>

using namespace std;

int n;
bool grid[3][3];

int occur[(1 << 9) + 5];

char input_char;

int arr_to_bitmask(void){
    int num = 0;

    for (int i=0; i != 3; i++){
        for (int j=0; j != 3; j++){
            num += (1 << (i * 3 + j)) * grid[i][j];
        }
    }

    return num;
}

void next_grid(void){
    int temp_grid[3][3];

    for (int i=0; i != 3; i++){
        for (int j=0; j != 3; j++){
            temp_grid[i][j] = 0;

            if (i > 0){
                temp_grid[i][j] += grid[i - 1][j];
            }

            if (i < 2){
                temp_grid[i][j] += grid[i + 1][j];
            }

            if (j > 0){
                temp_grid[i][j] += grid[i][j - 1];
            }

            if (j < 2){
                temp_grid[i][j] += grid[i][j + 1];
            }

            temp_grid[i][j] %= 2;
        }
    }

    for (int i=0; i != 3; i++){
        for (int j=0; j != 3; j++){
            grid[i][j] = (bool) temp_grid[i][j];
        }
    }

    return;
}


int main()
{
    scanf(" %d", &n);

    while (n--){

        for (int i = 0; i < (1 << 9) + 5; i++){
            occur[i] = -1;
        }

        for (int i=0; i != 3; i++){
            for (int j=0; j != 3; j++){
                scanf(" %c", &input_char);
                grid[i][j] = (input_char == '1');
            }
        }

        int mask = arr_to_bitmask();
        int ind = 0;


        while (occur[mask] == -1){
            occur[mask] = ind;
            ind++;
            next_grid();
            mask = arr_to_bitmask();
        }

        printf("%d\n", occur[mask] - 1);

    }
}
