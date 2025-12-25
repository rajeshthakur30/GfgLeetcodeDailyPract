#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        int start = 0, end = col - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            // Find row index of maximum element in mid column
            int maxRow = 0;
            for (int i = 0; i < row; i++) {
                if (mat[i][mid] > mat[maxRow][mid]) {
                    maxRow = i;
                }
            }

            int current = mat[maxRow][mid];
            int left  = (mid > 0) ? mat[maxRow][mid - 1] : INT_MIN;
            int right = (mid < col - 1) ? mat[maxRow][mid + 1] : INT_MIN;

            // Check peak condition
            if (current >= left && current >= right) {
                return {maxRow, mid};
            }
            else if (left > current) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return {-1, -1};
    }
};

int main() {
    vector<vector<int>> mat = {
        {1, 4},
        {3, 2}
    };

    Solution obj;
    vector<int> ans = obj.findPeakGrid(mat);

    cout << "Peak found at index: [" << ans[0] << ", " << ans[1] << "]" << endl;

    return 0;
}
