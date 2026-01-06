#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        int n = arr.size();

        // Edge case: if k is greater than array size
        if (k > n) return 0;

        int cur = 0;
        int maxXor = 0;

        for (int i = 0; i < n; i++) {
            cur ^= arr[i];   // add current element to window XOR

            if (i == k - 1) {
                maxXor = cur;   // first window
            }

            if (i >= k) {
                cur ^= arr[i - k];   // remove element going out of window
                maxXor = max(maxXor, cur);
            }
        }
        return maxXor;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {1, 2, 3, 4};
    int k = 2;

    cout << "Maximum Subarray XOR of size " << k << " is: ";
    cout << sol.maxSubarrayXOR(arr, k) << endl;

    return 0;
}
