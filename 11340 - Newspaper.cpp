#include <iostream>
#include <map>
#include <cstdio>
#include <cstring>

using namespace std;

int test_cases;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    scanf("%d", &test_cases);

    while (test_cases--){
        int chars;
        scanf(" %d", &chars);

        map <char,int> prices;

        int total = 0;

        char new_line_cap;

        for (int i=0; i != chars; i++){
            char key;
            int value;
            scanf(" %c %d",&key, &value);
            //printf("\"%c\" %d\n", key, value);
            prices[key] = value;
        }

        int lines;
        scanf(" %d", &lines);
        scanf("%c", &new_line_cap);

        for (int i=0; i != lines; i++){

            char next_char;

            while (scanf("%c", &next_char)){

                if (next_char == '\n'){
                    break;
                }

                map <char,int>::iterator it;

                it = prices.find(next_char);

                if (it != prices.end()){
                    total += it->second;
                }
            }
        }

        printf("%d.%02d$\n", total / 100, total % 100);
    }
}
