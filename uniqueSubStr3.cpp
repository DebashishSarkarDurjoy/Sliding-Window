#include <iostream>
#include <unordered_map>

using namespace std;

void uniqueSubStr(string input) {
    int i = 0;
    int j = 0;

    int max_i = 0;
    int max_j = 0;

    unordered_map<char, int> window;
    while (j < input.size()) {
        if ( window[input[j]] != 0 ) {
            while (i < j && input[i] != input[j]) {
                window[input[i]]--;
                i++;
            }
        }
        
        window[input[j]]++;
        if ( (max_j-max_i) < (j-i) ) {
            max_i = i+1;
            max_j = j;
        }
        j++;
    }
    // cout << max_i << " " << max_j << endl;

    int temp_i = max_i;
    while (temp_i <= max_j) {
        cout << input[temp_i];
        temp_i++;
    } 
    cout << endl;
}

int main(void) {
    string input;
    cout << "Enter string: " << endl;
    cin >> input;

    // cout << uniqueSubStr(input) << endl;
    uniqueSubStr(input);

    return 0;
}