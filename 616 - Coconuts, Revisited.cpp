#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;


bool input(int &n){
    scanf(" %d", &n);

    return (n >= 0);
}

bool long_check(int coconuts, int num_people){

    for (int i=0; i < num_people; i++){
        if (coconuts % num_people != 1) return false;
        coconuts -= coconuts / num_people;
        coconuts -= 1;
    }

    return !(coconuts % num_people);
}

vector <int> factor_list(int n){
    vector <int> factors;

    for (int i=1; i <= (int) sqrt(n) + 1; i++){
        if (n % i == 0){
            int a = i, b = n / i;

            if (a > b){
                break;
            }

            factors.push_back(a);

            if (a < b){
                factors.push_back(b);
            }
        }
    }

    return factors;
}


void solve(int coconuts){

    printf("%d coconuts, ", coconuts);

    vector <int> factors = factor_list(coconuts - 1);
    sort(factors.begin(), factors.end(), greater<int>());

    for (int i=0; i < factors.size(); i++){
        int num_people = factors[i];

        if (long_check(coconuts, num_people)){
            printf("%d people and 1 monkey\n", num_people);
            return;
        }
    }

    printf("no solution\n");

}

int main()
{
    ios::sync_with_stdio(false);

    int coconuts;
    while (input(coconuts)){
        solve(coconuts);
    }

}
