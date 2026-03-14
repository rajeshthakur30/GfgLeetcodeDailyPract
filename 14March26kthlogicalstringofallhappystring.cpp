#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    void solve(int n, string curr, vector<string>& ans) {
        if(curr.length() == n) {
            ans.push_back(curr);
            return;
        }

        for(char ch : {'a','b','c'}) {
            if(curr.empty() || curr.back() != ch) {
                solve(n, curr + ch, ans);
            }
        }
    }

    string getHappyString(int n, int k) {
        vector<string> ans;
        solve(n, "", ans);

        if(k > ans.size()) return "";
        return ans[k-1];
    }
};

int main() {
    Solution obj;

    int n = 3;
    int k = 9;

    string result = obj.getHappyString(n, k);

    if(result == "")
        cout << "No such string exists\n";
    else
        cout << "Kth Happy String: " << result << endl;

    return 0;
}