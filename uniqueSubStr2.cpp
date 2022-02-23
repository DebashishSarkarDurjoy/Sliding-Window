#include <iostream>
#include <unordered_map>

using namespace std;

string uniqueSubStr(string input) {
    int i = 0;
    int j = 0;

    unordered_map<char, int> m;

    int window_len = 0;
    int window_len_max = 0;
    int start_window = -1;

    while (j < input.length()) {
        int c = input[j];

        if (m.count(c) && m[c] >= i) {
            i = m[c] + 1;
            window_len = j - i;
        }

        m[c] = j;
        window_len++;
        j++;

        if (window_len > window_len_max) {
            window_len_max = window_len;
            start_window = i;
        }
    }

    return input.substr(start_window, window_len_max);
}

int main(void) {
    string input;
    cout << "Enter string: " << endl;
    cin >> input;

    cout << uniqueSubStr(input) << endl;

    return 0;
}
