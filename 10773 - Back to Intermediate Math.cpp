#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int num_cases;
int width, river, boat;

void input(){
    scanf(" %d %d %d", &width, &river, &boat);
}


void solve(){
    if (boat == 0){
        // boat can't go forward! - paths will be the same
        printf("can't determine\n");
    } else if (river == 0){
        // shortest path and fastest path are equal! - paths same
        printf("can't determine\n");
    } else if (boat <= river){
        // can't cancel out the effect of the river! - paths same
        printf("can't determine\n");
    } else if (boat > river){
        // difference between straight forward and cancelled out

        double boat_sqrd = boat * boat;
        double river_sqrd = river * river;

        double forward_speed_angle = sqrt(boat_sqrd - river_sqrd);
        double forward_speed_no_angle = boat;

        double dist = width;

        double time_angle = dist / forward_speed_angle;
        double time_no_angle = dist / forward_speed_no_angle;

        printf("%.3f\n", time_angle - time_no_angle);
    }

}


int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &num_cases);

    for (int case_num = 1; case_num <= num_cases; case_num++){
        input();
        printf("Case %d: ", case_num);
        solve();
    }
}
