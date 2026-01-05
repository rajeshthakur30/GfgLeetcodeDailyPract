#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int countNeg = 0;
        int mini = INT_MAX;

        int n = matrix.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                sum += abs(matrix[i][j]);
                if (matrix[i][j] < 0) countNeg++;
                mini = min(mini, abs(matrix[i][j]));
            }
        }

        // If number of negative elements is odd
        if (countNeg % 2 != 0) {
            sum -= 2LL * mini;
        }

        return sum;
    }
};

int main() {
    Solution obj;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, -1},
        {-1, 1}
    };

    cout << "Maximum Matrix Sum: "
         << obj.maxMatrixSum(matrix) << endl;

    return 0;
}
