#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> isFlipped(n, 0);
        int flip = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {

            // remove flip effect leaving window
            if (i >= k) {
                flip ^= isFlipped[i - k];
            }

            // if current bit becomes 0
            if ((nums[i] ^ flip) == 0) {

                if (i + k > n) return -1;

                ans++;
                flip ^= 1;
                isFlipped[i] = 1;
            }
        }

        return ans;
    }
};

int main() {
    vector<int> nums = {0,1,0};
    int k = 1;

    Solution obj;
    cout << obj.minKBitFlips(nums, k);

    return 0;
}