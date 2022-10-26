#include <iostream>
using namespace std;

string findWindow(string s, string p) {
    int FS[256] = {0};
    int FP[256] = {0};

    for (char c: p) {
        FP[c]++;
    }

    int j = 0;
    int i = 0;
    int start_idx = 0;
    int cnt = 0;
    int window_len = 0;
    int min_window_len = INT_MAX;
    while (j < s.length()) {
        char current_char = s[j];
        FS[current_char]++;

        if (FP[current_char] && FP[current_char] >= FS[current_char]) {
            cnt++;
        }

        if (cnt == p.length()) {
            while (FP[s[i]] == 0 || FP[s[i]] < FS[s[i]]) {
                FS[s[i]]--;
                i++;
            }

            window_len = j - i + 1;
            if (window_len < min_window_len) {
                min_window_len = window_len;
                start_idx = i;
            }
        }
        j++;
    }
 
    return s.substr(start_idx, min_window_len);
}

int main(void) {
    string s, p;
    cin >> s >> p;

    cout << findWindow(s, p) << endl;

    return 0;
}