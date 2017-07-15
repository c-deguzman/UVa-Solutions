#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    while (true){
        int n;
        scanf(" %d", &n);

        if (!n){
            break;
        }

        priority_queue<int, vector<int>, greater<int> > nums;

        for (int i=0; i != n; i++){
            int inp;
            scanf(" %d", &inp);

            nums.push(inp);
        }

        int total_cost = 0;

        while (nums.size() > 1){
            int a = nums.top();
            nums.pop();
            int b = nums.top();
            nums.pop();

            total_cost += (a + b);
            nums.push(a + b);
        }

        printf("%d\n", total_cost);
    }
}
