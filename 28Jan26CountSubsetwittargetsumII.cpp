#include <bits/stdc++.h>
using namespace std;

int countSubsetsWithTargetSum(vector<int>& arr, int target) {
    int n = arr.size();

    // dp[i][j] = number of subsets using first i elements with sum j
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    // Base case: sum = 0 -> one subset (empty subset)
    for (int i = 0; i <= n; i++) {
        dp[i][0] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= target; j++) {
            // Not take the element
            dp[i][j] = dp[i - 1][j];

            // Take the element if possible
            if (j >= arr[i - 1]) {
                dp[i][j] += dp[i - 1][j - arr[i - 1]];
            }
        }
    }

    return dp[n][target];
}

int main() {
    int n, target;
    cin >> n >> target;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << countSubsetsWithTargetSum(arr, target) << endl;

    return 0;
}
