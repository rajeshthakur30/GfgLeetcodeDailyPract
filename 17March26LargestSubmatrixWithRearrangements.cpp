#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;

        // Step 1: Build heights of consecutive 1s
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] += matrix[i - 1][j];
                }
            }
        }

        // Step 2: For each row, sort in descending order
        for (int i = 0; i < m; i++) {
            sort(matrix[i].rbegin(), matrix[i].rend());

            // Step 3: Calculate max area
            for (int j = 0; j < n; j++) {
                res = max(res, matrix[i][j] * (j + 1));
            }
        }

        return res;
    }
};

int main() {
    Solution obj;

    // Example matrix
    vector<vector<int>> matrix = {
        {0, 0, 1},
        {1, 1, 1},
        {1, 0, 1}
    };

    int result = obj.largestSubmatrix(matrix);
    cout << "Largest Submatrix Area: " << result << endl;

    return 0;
}