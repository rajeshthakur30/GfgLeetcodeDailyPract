#include <bits/stdc++.h>
using namespace std;

// Function to count substrings with at most K distinct characters
long long countAtMostK(string &s, int k) {
    if (k < 0) return 0;

    vector<int> freq(26, 0);
    int left = 0, distinct = 0;
    long long count = 0;

    for (int right = 0; right < s.size(); right++) {
        if (freq[s[right] - 'a'] == 0)
            distinct++;
        freq[s[right] - 'a']++;

        while (distinct > k) {
            freq[s[left] - 'a']--;
            if (freq[s[left] - 'a'] == 0)
                distinct--;
            left++;
        }

        count += (right - left + 1);
    }

    return count;
}

// Function to count substrings with exactly K distinct characters
long long countExactlyK(string &s, int k) {
    return countAtMostK(s, k) - countAtMostK(s, k - 1);
}

int main() {
    string s;
    int k;

    cout << "Enter string: ";
    cin >> s;

    cout << "Enter K: ";
    cin >> k;

    cout << "Substrings with exactly " << k 
         << " distinct characters = "
         << countExactlyK(s, k) << endl;

    return 0;
}
