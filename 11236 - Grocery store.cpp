#include <iostream>
#include <cstdio>

using namespace std;

const unsigned long long int mil = 1e6;

int main()
{
    ios::sync_with_stdio(false);

    for (unsigned long long int a = 1; a * 4 <= 2000; a++){
        for (unsigned long long int b = a; a + b * 3 <= 2000; b++){
            for (unsigned long long int c = b; a + b + c * 2 <= 2000; c++){

                if (a * b * c <= mil){
                    continue;
                }

                if ((mil * (a + b + c)) % (a * b * c - mil)){
                    continue;
                }

                unsigned long long int d = ((mil * (a + b + c)) / (a * b * c - mil));

                if (d == 0 || d > 2000 || !(a <= b && b <= c && c <= d) || (a + b + c + d) > 2000){
                    continue;
                }

                printf("%lld.%02lld %lld.%02lld %lld.%02lld %lld.%02lld\n", a / 100, a % 100, b / 100, b % 100, c / 100, c % 100, d / 100, d % 100);
            }
        }
    }
}
