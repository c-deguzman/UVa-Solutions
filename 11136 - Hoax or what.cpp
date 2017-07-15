#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int n;

int main()
{
    ios::sync_with_stdio(false);

    while (true){
        scanf(" %d", &n);

        if (!n){
            break;
        }

        multiset <int> urn;

        long long int total_cost = 0;

        for (int qq = 0; qq < n; qq++){
            int bills;
            scanf(" %d", &bills);

            for (int i = 0; i != bills; i++){
                int inp_bill;
                scanf(" %d", &inp_bill);
                urn.insert(inp_bill);
            }

            total_cost += (long long int) *urn.rbegin() - *urn.begin();

            urn.erase(urn.begin());
            urn.erase(prev(urn.end()));

        }

        printf("%lld\n", total_cost);

    }
}
