#include <bits/stdc++.h>

using namespace std;

vector <int> ans;

int t;

int main()
{
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;

        int poss[105];

        for (int i=0; i <= n + 2; i++){
            poss[i] = -1;
        }

        bool ineq = false;


        for (int i=0; i!= k; i++){
            int c;
            cin >> c;

            vector <int> left_pan, right_pan;

            left_pan.resize(0);
            right_pan.resize(0);

            for (int j=0; j != c; j++){
                int inp_coin;
                cin >> inp_coin;
                left_pan.push_back(inp_coin);
            }


            for (int j=0; j != c; j++){
                int inp_coin;
                cin >> inp_coin;
                right_pan.push_back(inp_coin);
            }

            string sign;
            cin >> sign;

            if (sign[0] == '='){
                for (int j=0; j != c; j++){
                    poss[left_pan[j]] = 0;
                    poss[right_pan[j]] = 0;
                }
            } else {

                ineq = true;

                for (int j = 0; j != c; j++){
                    if (poss[left_pan[j]] == -1){
                        poss[left_pan[j]] = 1;
                    }

                    if (poss[right_pan[j]] == -1){
                        poss[right_pan[j]] = 1;
                    }
                }
            }
        }


        int count_poss = 0;
        int count_unk = 0;

        for (int j=1; j <= n; j++){
            if (poss[j] != -1){
                if (poss[j] == 1){
                    count_poss++;
                }
            } else {
                count_unk++;
            }
        }

        int local_ans;

        if (ineq){
            if (count_poss != 1){
                local_ans = 0;
            } else {
                for (int j=1; j <= n; j++){
                    if (poss[j] == 1){
                        local_ans = j;
                    }
                }
            }
        } else {
            if (count_unk != 1){
                local_ans = 0;
            } else {
                for (int j=1; j <= n; j++){
                    if (poss[j] == -1){
                        local_ans = j;
                    }
                }
            }
        }

        ans.push_back(local_ans);
    }

    for (int i=0; i != ans.size(); i++){
        cout << ans[i] << endl;
        if (i < ans.size() - 1){
            cout << endl;
        }
    }
}
