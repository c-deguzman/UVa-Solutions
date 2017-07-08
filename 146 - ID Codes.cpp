#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char str[55];

int main()
{
    while (true){
        scanf(" %s", &str);

        if (str[0] == '#'){
            break;
        }

        int length = strlen(str);

        if (next_permutation(str, str + length)){
            printf("%s\n", str);
        } else {
            printf("No Successor\n");
        }
    }
}
