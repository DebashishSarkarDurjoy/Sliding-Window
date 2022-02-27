#include <iostream>
using namespace std;

string findWindow(string s, string p) {
    int start_idx = -1;
    int min_so_far = INT_MAX;

    int FP[256] = {0};
    int FS[256] = {0};

    for (char c: p) {
        FP[c]++;
    }

    int count = 0;
    int start = 0;
    int window_len;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        FS[ch]++;

        if ( (FP[ch] != 0) && (FP[ch] >= FS[ch]) ) {
            count++;
        }

        if ( count == p.length() ) {
            while ( (FS[s[start]] > FP[s[start]]) || (FP[s[start]] == 0) ) {
                FS[s[start]]--;
                start++;
            }

            window_len = i - start + 1;
            if (window_len < min_so_far) {
                min_so_far = window_len;
                start_idx = start;
            }
        }
    }

    if (start_idx == -1) return "No window found\n";
    else return s.substr(start_idx, min_so_far);
}

int main(void) {
    string s, p;
    cin >> s >> p;

    cout << findWindow(s, p) << endl;

    return 0;
}
