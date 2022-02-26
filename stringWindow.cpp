#include <iostream>
using namespace std;

string find_window(string s, string p) {
    int FP[256] = {0};
    int FS[256] = {0};

    for (int i = 0; i < p.length(); i++) {
        FP[p[i]]++;
    }

    int count = 0;
    int start = 0;
    int window_size;
    int min_so_far = INT_MAX;
    int start_idx = -1;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        FS[ch]++;

        if ( (FP[ch] != 0) && (FP[ch] >= FS[ch]) ) {
            count++;
        }

        if (count == p.length()) {
            while ( (FP[s[start]] == 0) || (FS[s[start]] > FP[p[start]]) ) {
                FS[s[start]]--;
                start++;
            }

            window_size = i - start + 1;
            if (window_size < min_so_far) {
                min_so_far = window_size;
                start_idx = start;
            }
        }

    }

    if (start_idx == -1) {
        return "no window found\n";
    }
    else {
        return s.substr(start_idx, min_so_far);
    }
}

int main(void) {
    string s, p;
    cin >> s >> p;

     cout << find_window(s, p) << endl;

    return 0;
}
