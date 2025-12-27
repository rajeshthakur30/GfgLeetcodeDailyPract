#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int low = mat[0][0];
        int high = mat[n-1][n-1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Count elements <= mid
            int count = 0;
            for (int i = 0; i < n; i++) {
                count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }

            if (count >= k) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> mat = {
        {16, 28, 60, 64},
        {22, 41, 63, 91},
        {27, 50, 87, 93},
        {36, 78, 87, 94}
    };
    int k = 3;

    Solution obj;
    cout << obj.kthSmallest(mat, k);
    return 0;
}
