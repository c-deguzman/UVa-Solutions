#include <iostream>
#include <cstdio>

using namespace std;

int n;

int results[185][2];

void line(void){
    for (int i=0; i < 70; i++){
        printf("*");
    }
    printf("\n");
}

void add_result(int a, int b, int c){
    results[a + b + c][0]++;

    if (a == b && b == c){
        results[a + b + c][1] += 1;
    } else if (a == b || b == c){
        results[a + b + c][1] += 3;
    } else {
        results[a + b + c][1] += 6;
    }
}

bool non_mult(int num){

    if (num == 50){
        return false;
    }

    if (num <= 20){
        return false;
    }

    if (num % 2 == 0 && num / 2 <= 20){
        return false;
    }

    if (num % 3 == 0 && num / 3 <= 20){
        return false;
    }

    return true;
}

void init()
{
    for (int a = 0; a <= 60; a++){

        if (non_mult(a)){
            continue;
        }

        for (int b = 0; b <= 60; b++){

            if (non_mult(b) || b > a){
                continue;
            }

            for (int c = 0; c <= 60; c++){
                if (non_mult(c) || c > b){
                    continue;
                }

                add_result(a,b,c);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    init();

    while (scanf(" %d", &n) == 1){
        if (n <= 0){
            printf("END OF OUTPUT\n");
            break;
        }


        if (n <= 180 && results[n][0] && results[n][1]){
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n", n, results[n][0]);
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, results[n][1]);
        } else {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        }


        line();
    }
}
