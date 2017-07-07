#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;

    while (cin >> n){
        int num1, num2;

        bool jolly = true;

        bool arr[3005];

        for (int i=0; i != 3005; i++){
            arr[i] = false;
        }


        if (n == 1){
            cin >> num1;
            cout << "Jolly" << endl;
        } else {
            cin >> num1;

            for (int i=1; i < n; i++){
                cin >> num2;

                if (abs(num1 - num2) >= n || num1 == num2){
                    jolly = false;
                }

                arr[(int) abs(num1 - num2)] = true;

                num1 = num2;
            }

            for (int i = 1; i < n; i++){
                if (!arr[i]){
                    jolly = false;
                }
            }

            if (jolly){
                cout << "Jolly" << endl;
            } else {
                cout << "Not jolly" << endl;
            }
        }
    }
}
