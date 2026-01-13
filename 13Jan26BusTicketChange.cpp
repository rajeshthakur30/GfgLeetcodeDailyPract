#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool canServe(vector<int> &arr) {
        int cntFive = 0, cntTen = 0;

        for (int bill : arr) {
            if (bill == 5) {
                cntFive++;
            }
            else if (bill == 10) {
                if (cntFive == 0) return false;
                cntFive--;
                cntTen++;
            }
            else if (bill == 20) {
                if (cntTen > 0 && cntFive > 0) {
                    cntTen--;
                    cntFive--;
                } else if (cntFive >= 3) {
                    cntFive -= 3;
                } else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << (obj.canServe(arr) ? "true" : "false") << "\n";
    return 0;
}
