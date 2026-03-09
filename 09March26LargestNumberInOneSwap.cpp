#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestSwap(string &s) {
        int n = s.size();
        vector<int> maxi(n, 0);

        // Store index of maximum digit from right
        maxi[n - 1] = n - 1;

        for (int i = n - 2; i >= 0; i--) {
            if (s[i] > s[maxi[i + 1]])
                maxi[i] = i;
            else
                maxi[i] = maxi[i + 1];
        }

        // Find first place where swap increases number
        for (int i = 0; i < n; i++) {
            if (i != maxi[i] && s[i] != s[maxi[i]]) {
                swap(s[i], s[maxi[i]]);
                return s;
            }
        }

        return s;
    }
};

int main() {
    string s;
    cout << "Enter number string: ";
    cin >> s;

    Solution obj;
    string result = obj.largestSwap(s);

    cout << "Largest number after one swap: " << result << endl;

    return 0;
}