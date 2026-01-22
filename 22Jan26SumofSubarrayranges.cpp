#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long sumMax = 0, sumMin = 0;

        // ---------- Sum of subarray minimums ----------
        vector<int> leftMin(n), rightMin(n);
        stack<int> st;

        // previous strictly smaller element index distance
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            leftMin[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next smaller or equal element index distance
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            rightMin[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            sumMin += 1LL * nums[i] * leftMin[i] * rightMin[i];
        }

        // ---------- Sum of subarray maximums ----------
        vector<int> leftMax(n), rightMax(n);
        while (!st.empty()) st.pop();

        // previous strictly greater element index distance
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] < nums[i]) st.pop();
            leftMax[i] = st.empty() ? (i + 1) : (i - st.top());
            st.push(i);
        }

        while (!st.empty()) st.pop();

        // next greater or equal element index distance
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) st.pop();
            rightMax[i] = st.empty() ? (n - i) : (st.top() - i);
            st.push(i);
        }

        for (int i = 0; i < n; i++) {
            sumMax += 1LL * nums[i] * leftMax[i] * rightMax[i];
        }

        return sumMax - sumMin;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;                 // size of array
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol;
    cout << sol.subArrayRanges(nums) << "\n";
    return 0;
}
