#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int t;

int find_root(int _root[], int a){
    if (_root[a] != a){
        return _root[a] = find_root(_root, _root[a]);
    }

    return a;
}

void _union(int _root[], int _rank[], int _size[], int a, int b){

    int root_a = find_root(_root, a);
    int root_b = find_root(_root, b);

    if (root_a == root_b){
        return;
    }

    if (_rank[root_a] >= _rank[root_b]){
        _size[root_a] += _size[root_b];
        _root[root_b] = root_a;

        if (_rank[root_a] == _rank[root_b]){
            _rank[root_a]++;
        }
    } else {
        _size[root_b] += _size[root_a];
        _root[root_a] = root_b;
    }
}

int main()
{
    ios::sync_with_stdio(false);

    scanf(" %d", &t);

    while (t--){

        int _root[27], _rank[27], _size[27];

        for (int i=0; i != 27; i++){
            _root[i] = i;
            _rank[i] = 0;
            _size[i] = 1;
        }

        char inp_str[10];

        while(scanf(" %s", &inp_str) == 1){
            if (inp_str[0] == '*'){
                break;
            }

            int a_ind = inp_str[1] - 'A';
            int b_ind = inp_str[3] - 'A';


            _union(_root, _rank, _size, a_ind, b_ind);
        }

        char inp_nodes[60];
        scanf(" %s", &inp_nodes);

        int inp_nodes_len = strlen(inp_nodes);

        int trees = 0, acorns = 0;

        for (int i=0; i < inp_nodes_len; i+= 2){

            int node = inp_nodes[i] - 'A';

            if (_root[node] == node){
                if (_size[node] > 1){
                    trees++;
                } else {
                    acorns++;
                }
            }
        }

        printf("There are %d tree(s) and %d acorn(s).\n", trees, acorns);

    }
}
