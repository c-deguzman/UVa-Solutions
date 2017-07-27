#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int t;
pair < pair <int, int>, string > ranges[10005];
int makers;

bool in_range(int price, int ind){
    return (ranges[ind].first.first <= price && ranges[ind].first.second >= price);
}

int solve_maker(int price){
    int ans = -1;

    for (int i=0; i != makers; i++){
        if (in_range(price, i)){
            if (ans != -1){
                return -1;
            }
            ans = i;
        }
    }

    return ans;
}


int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> t;

    while (t--){

        cin >> makers;

        for (int i=0 ; i != makers; i++){
            string maker;
            int low, hi;

            cin >> maker >> low >> hi;
            ranges[i] = make_pair(make_pair(low,hi), maker);
        }

        int queries;
        cin >> queries;

        while (queries--){
            int price;
            cin >> price;

            int res = solve_maker(price);

            if (res < 0){
                cout << "UNDETERMINED" << endl;
            } else {
                cout << ranges[res].second << endl;
            }
        }

        if (t){
           cout << endl;
        }
    }
}
