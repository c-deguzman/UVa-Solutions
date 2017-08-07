#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

double p, q, r, s, t, u;

const double e = exp(1.0);
const double eps = 1e-6;

bool double_eq(double a, double b){
    return (abs(a - b) < eps);
}

double eval(double x){
    return (p * pow(e, -1.0 * x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u);
}

void print_ans(double ans){
    printf("%.4f\n", ans);
}

int main()
{

    while (scanf(" %lf %lf %lf %lf %lf %lf", &p, &q, &r, &s, &t, &u) == 6){
        double hi = 1;
        double lo = 0;

        if (double_eq(eval(hi), 0)){
            print_ans(hi);
            continue;
        } else if (double_eq(eval(lo), 0)){
            print_ans(lo);
            continue;
        } else if ((eval(hi) > 0) == (eval(lo) > 0)){
            printf("No solution\n");
            continue;
        }

        double ans = -1;

        for (int i=0; i < 50; i++){
            double mid = (hi + lo) / 2.0;
            double calc_mid = eval(mid);

            if (double_eq(calc_mid, 0)){
                ans = mid;
                break;
            } else if (calc_mid > 0){
                lo = mid;
            } else {
                hi = mid;
            }
        }

        if (!double_eq(ans, -1.0)){
            print_ans(ans);
        } else {
            printf("No solution\n");
        }
    }
}
