#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int josephus(int n, int k) {
        int ans = 0; // 0-based
        for (int i = 1; i <= n; i++) {
            ans = (ans + k) % i;
        }
        return ans + 1; // convert to 1-based
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    Solution ob;
    cout << ob.josephus(n, k) << "\n";

    return 0;
}
