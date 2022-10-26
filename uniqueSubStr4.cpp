#include <iostream>
#include <unordered_map>

using namespace std;

string unique_substring(string input) {
    unordered_map<char, int> m;
    int i = 0;
    int j = 0;
    int start_index = 0;

    int window_len = 0;
    int max_window_len = 0;

    while (j < input.length()) {
        char c = input[j];

        if (m.count(c) && m[c] >= i) {
            i = m[c] + 1;
            window_len = j - i;
        }

        m[c] = j;
        window_len++;
        if (window_len > max_window_len) {
            max_window_len = window_len;
            start_index = i;
        }
        j++;
    }

    return input.substr(start_index, max_window_len);
}

int main(void) {
    string input;
    cout << "Enter string: " << endl;
    cin >> input;
    cout << unique_substring(input) << endl;
}