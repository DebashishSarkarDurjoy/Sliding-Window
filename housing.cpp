#include <iostream>
using namespace std;

void housing(int *arr, int n, int k) {
    int i = 0;
    int j = 0;
    int cs = 0;

    while (j < n) {
        cs = arr[j] + cs;
        j++;

        while (cs > k && i < j) {
            cs = cs - arr[i];
            i++;
        }

        if (cs == k) {
            cout << i << " - " << j - 1 << endl;
        }

    }

    return ;
}


int main() {

    int plot[] = {1, 3, 2, 1, 4, 1, 3, 2, 1, 1};
    int n = sizeof(plot) / sizeof(int);
    int k = 8;

    housing(plot, n, k);


    return 0;
}
