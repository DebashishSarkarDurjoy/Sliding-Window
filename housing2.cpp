#include <iostream>
using namespace std;

class Pair {
public:
    int i;
    int j;

    Pair() {
        this->i = -1;
        this->j = -1;
    }
};

Pair housing(int *arr, int k, int n) {
    int i = 0;
    int j = 0;
    Pair p;

    int cs = 0;
    while (j < n) {
        cs = arr[j] + cs;

        while (i < j && cs > k) {
            cs = cs - arr[i];
            i++;
        }

        if (cs == k) {
            break;
        }
        
        j++;
    }

    p.i = i;
    p.j = j;

    return p;
}

int main(void) {
    int plot[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plot) / sizeof(int);
    int k = 8;

    Pair pointers = housing(plot, k, n);
    cout << pointers.i << " " << pointers.j << endl;

    return 0;
}
