#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMen(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> v(n, -1);  // v[l] = farthest r reachable starting coverage at l

        for (int i = 0; i < n; i++) {
            if (arr[i] == -1) continue;
            int l = max(0, i - arr[i]);
            int r = min(n - 1, i + arr[i]);
            v[l] = max(v[l], r);
        }

        if (n == 0) return 0;
        if (v[0] == -1) return -1;

        int curr = v[0], cnt = 1;
        int j = 1;

        while (curr < n - 1) {
            int maxi = -1;

            // consider all starts l in [j..curr]
            while (j <= curr) {
                maxi = max(maxi, v[j]);
                j++;
            }

            if (maxi <= curr) return -1;
            curr = maxi;
            cnt++;
        }
        return cnt;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution sol;
    cout << sol.minMen(arr) << "\n";
    return 0;
}
