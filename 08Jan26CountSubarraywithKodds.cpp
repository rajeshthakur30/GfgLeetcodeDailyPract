#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubarrays(vector<int>& arr, int k) {
        int n = arr.size();
        int ans = 0, cnt = 0, last = 0, j = 0;

        for (int i = 0; i < n; i++) {

            // if current element is odd
            if (arr[i] % 2) {
                cnt++;
                last = 0;
            }

            // shrink window while odd count >= k
            while (j <= i && cnt >= k) {
                if (arr[j] % 2) {
                    cnt--;
                }
                j++;
                last++;
            }

            // add number of valid subarrays ending at i
            ans += last;
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<int> arr = {2, 2, 1, 2, 1, 2};
    int k = 2;

    cout << sol.countSubarrays(arr, k) << endl;

    return 0;
}
