#include <iostream>
#include <iomanip>
#include <cstdio>
#include <sstream>
#include <cmath>

/*
    Interesting problem - Eulerian tour.
    An Eulerian tour is possible if and only if all vertices have an even degree.
    Note by construction there will always exist a Eulerian tour - starting and ending at the hangar:
        - since all roads are effectively treated as two separate edges

    The Eulerian tour must be the lowest cost tour because it visits every path only once.

*/

using namespace std;

int test_cases;
double total_dist = 0;

void input(){

    total_dist = 0;

    int a, b, c, d;
    cin >> a >> b;

    string line;
    getline(cin, line);

    while (getline(cin, line)){
        if (line.empty()) break;
        stringstream ss(line);

        ss >> a >> b >> c >> d;

        total_dist += sqrt((double) ((a - c) * (a - c) + (b - d) * (b - d)));
    }

    double fractional, whole;
    fractional = std::modf(total_dist * 2.0 / 1000.0 / 20.0, &whole);

    if (round(fractional * 60) >= 60.0){
        fractional = 0;
        whole += 1;
    }

    cout << whole << ":" << setfill('0') << setw(2) << round(fractional * 60) << endl;

    if (test_cases){
        cout << endl;
    }

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> test_cases;

    while (test_cases--){
        input();
    }
}
