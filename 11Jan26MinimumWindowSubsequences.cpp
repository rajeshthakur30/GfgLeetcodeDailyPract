#include <bits/stdc++.h>
using namespace std;

string minWindowSubsequence(string S, string T) {
    int n = S.size(), m = T.size();
    int minLen = INT_MAX;
    int start = -1;

    int i = 0;
    while (i < n) {
        int j = 0;

        // Step 1: Forward match T as subsequence
        while (i < n) {
            if (S[i] == T[j]) j++;
            if (j == m) break;
            i++;
        }

        if (j < m) break; // T not found

        // Step 2: Backward shrink window
        int end = i;
        j = m - 1;

        while (i >= 0) {
            if (S[i] == T[j]) j--;
            if (j < 0) break;
            i--;
        }

        // Update minimum window
        int windowLen = end - i;
        if (windowLen < minLen) {
            minLen = windowLen;
            start = i + 1;
        }

        i = i + 1; // move forward for next search
    }

    return (start == -1) ? "" : S.substr(start, minLen);
}

int main() {
    string S, T;
    cin >> S >> T;
    cout << minWindowSubsequence(S, T);
    return 0;
}
