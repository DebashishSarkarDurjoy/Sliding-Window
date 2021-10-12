#include <iostream>
#include <unordered_map>
using namespace std;


string unique_substring(string str) {
    int i = 0;
    int j = 0;

    unordered_map<char, int> m;

    int window_len = 0;
    int max_window_len = 0;
    int start_index = -1;

    while (j < str.length()) {
        char c = str[j];

        if (m.count(c) && m[c] >= i) {
            i = m[c] + 1;
            window_len = j - i;
        }

        m[c] = j;
        window_len++;
        j++;

        if (window_len > max_window_len) {
            max_window_len = window_len;
            start_index = i;
        }
    }
    return str.substr(start_index, max_window_len);
}

int main() {
    string input;
    cout << "Enter string: " << endl;
    cin >> input;
    cout << unique_substring(input) << endl;
}
