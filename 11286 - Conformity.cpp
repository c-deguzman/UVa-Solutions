#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int course_num = 5;

int students;

int update_map(std::map < vector <int> , int> &course_count, vector <int> &course){

    map < vector <int> , int>::iterator it;
    sort(course.begin(), course.end());

    int total_opt;

    if ((it = course_count.find(course)) == course_count.end()){
        course_count.insert(make_pair(course, 1));
        total_opt = 1;
    } else {
        total_opt = course_count[course] = course_count[course] + 1;
    }

    return total_opt;
}

int main()
{

    while (true){
        scanf(" %d", &students);

        if (students == 0){
            break;
        }

        map < vector <int> , int> course_count;

        int hi = -1;
        int tie_hi = 0;

        for (int i=0; i != students; i++){

            vector <int> inp;

            for (int j=0; j != course_num; j++){
                int inp_course;
                scanf(" %d", &inp_course);

                inp.push_back(inp_course);
            }

            int local_attempt = update_map(course_count, inp);

            if (local_attempt > hi){
                hi = local_attempt;
                tie_hi = 1;
            } else if (local_attempt == hi){
                tie_hi++;
            }
        }

        printf("%d\n", tie_hi * hi);
    }
}
