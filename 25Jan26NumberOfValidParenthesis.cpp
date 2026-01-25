#include <bits/stdc++.h>
using namespace std;

int countValidPairs(string s) {
    int open = 0, pairs = 0;
    for (char c : s) {
        if (c == '(') open++;
        else {
            if (open > 0) {
                open--;
                pairs++;
            }
        }
    }
    return pairs; // number of matched pairs
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << countValidPairs(s) << "\n";
    return 0;
}
