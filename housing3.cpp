#include <iostream>
using namespace std;

class Pair {
public:
    int i;
    int j;

    Pair(int a, int b) {
        this->i = a;
        this->j = b;
    }
};

Pair housing(int plot[], int k, int n) {
    int i = 0;
    int j = 0;
    int acc = 0;

    while (j < n) {
        acc = acc + plot[j];
        

        while (acc > k && i < j) {
            acc = acc - plot[i];
            i++;
        }

        if (acc == k) return {i, j};
        j++;
    }

    return {-1,-1};
}

int main(void) {
    int plot[] = {1,3,2,1,4,1,3,2,1,1};
    int n = sizeof(plot) / sizeof(int);
    int k = 8;

    Pair pointers = housing(plot, k, n);
    cout << pointers.i << " " << pointers.j << endl;

    return 0;
}