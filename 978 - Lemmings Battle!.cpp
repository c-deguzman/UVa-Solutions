#include <iostream>
#include <cstdio>
#include <set>
#include <queue>

using namespace std;

int t;

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){

        int b, sg, sb;
        scanf(" %d %d %d", &b, &sg, &sb);

        multiset <int> green, blue;

        for (int i=0; i < sg; i++){
            int inp;
            scanf(" %d", &inp);
            green.insert(inp);
        }

        for (int i=0; i < sb; i++){
            int inp;
            scanf(" %d", &inp);
            blue.insert(inp);
        }

        int round = 0;

        while ((*green.rbegin()) > 0 && (*blue.rbegin()) > 0){

            round++;

            queue <int> update_green, update_blue;

            for (int i=0; i < b; i++){
                if (green.empty() || blue.empty() || (*green.rbegin()) <= 0 || (*blue.rbegin()) <= 0){
                    break;
                }

                int green_cand, blue_cand;

                blue_cand = -1 * (green_cand = (*green.rbegin()) - (*blue.rbegin()));

                update_green.push(green_cand);
                update_blue.push(blue_cand);

                green.erase(prev(green.end()));
                blue.erase(prev(blue.end()));

            }

            while (!update_green.empty()){
                green.insert(update_green.front());
                blue.insert(update_blue.front());
                update_green.pop();
                update_blue.pop();
            }
        }

        if (*green.rbegin() > 0){
            printf("green wins\n");

            while (!green.empty() && *green.rbegin() > 0){
                printf("%d\n", *green.rbegin());
                green.erase(prev(green.end()));
            }

        } else if (*blue.rbegin() > 0){
            printf("blue wins\n");

            while (!blue.empty() && *blue.rbegin() > 0){
                printf("%d\n", *blue.rbegin());
                blue.erase(prev(blue.end()));
            }
        } else {
            printf("green and blue died\n");
        }

        if (t){
            printf("\n");
        }
    }
}
