#include <iostream>
#include <cstdio>
#include <map>
#include <array>

using namespace std;

int t;

int find_root(int _root[], int a){
    if (_root[a] != a){
        return _root[a] = find_root(_root, _root[a]);
    }
    return a;
}

int _union(int _root[], int _rank[], int _size[], int a, int b){
    int root_a = find_root(_root, a);
    int root_b = find_root(_root, b);

    if (root_a == root_b){
        return _size[root_a];
    }

    if (_rank[root_a] < _rank[root_b]){
        _root[root_a] = root_b;
        _size[root_b] += _size[root_a];

        return _size[root_b];
    } else {
        _root[root_b] = root_a;
        _size[root_a] += _size[root_b];

        if (_rank[root_a] == _rank[root_b]){
            _rank[root_a]++;
        }

        return _size[root_a];
    }
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){

        map < array<char, 30> , int > dir;

        int curr_p = 1;
        int _root[100005];
        int _rank[100005];
        int _size[100005];

        for (int i=0; i != 100005; i++){
            _root[i] = i;
            _size[i] = _rank[i] = 1;
        }

        int n;
        scanf(" %d", &n);

        while (n--){
            array <char, 30> name1, name2;
            int ind1, ind2;

            scanf(" %s", &name1);
            scanf(" %s", &name2);

            if (!dir[name1]){
                dir[name1] = curr_p;
                curr_p++;
            }

            if (!dir[name2]){
                dir[name2] = curr_p;
                curr_p++;
            }

            printf("%d\n", _union(_root, _rank, _size, dir[name1], dir[name2]));
        }
    }
}
