#include <bits/stdc++.h>

using namespace std;

int n;
vector < string > arr;
string row;

int main()
{
    while (true){
        cin >> n;
        arr.clear();

        if (n == 0){
            break;
        }

        char endl_char;
        cin >> endl_char;

        for (int i=0; i!= n ; i++){
            getline(cin, row);
            arr.push_back(row);
        }

        int total_b = 0;
        int shortest_row = 50;

        for (int i=0; i != n ; i++){

            int row_b = 0;

            for (int j=0; j != arr[i].size(); j++){
                if (arr[i][j] == ' '){
                    total_b++;
                    row_b++;
                }
            }

            shortest_row = min(shortest_row, row_b);
        }

        cout << total_b - arr.size() * shortest_row << endl;

    }
}
