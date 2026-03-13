#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    void solve(string &s, int index, int parts, string current, vector<string> &ans) {

        if (parts == 4 && index == s.size()) {
            current.pop_back(); 
            ans.push_back(current);
            return;
        }

        if (parts >= 4) return;

        for (int len = 1; len <= 3 && index + len <= s.size(); len++) {

            string segment = s.substr(index, len);

            if ((segment[0] == '0' && segment.size() > 1) || stoi(segment) > 255)
                continue;

            solve(s, index + len, parts + 1, current + segment + ".", ans);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        solve(s, 0, 0, "", ans);
        return ans;
    }
};

int main() {

    string s;
    cout << "Enter numeric string: ";
    cin >> s;

    Solution obj;
    vector<string> result = obj.restoreIpAddresses(s);

    cout << "Possible IP Addresses:\n";

    for (string ip : result) {
        cout << ip << endl;
    }

    return 0;
}