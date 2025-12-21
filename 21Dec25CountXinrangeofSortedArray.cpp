
//in this we we find first ocdcurence using binary search because array is in sorted form and find last occurences using binary search and cobine both we get the result
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Find first occurrence of target in range [left, right]
    int firstOccurence(vector<int>& nums, int left, int right, int target) {
        int first = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                first = mid;
                right = mid - 1;   // search left side
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return first;
    }

    // Find last occurrence of target in range [left, right]
    int lastOccurence(vector<int>& nums, int left, int right, int target) {
        int last = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                last = mid;
                left = mid + 1;   // search right side
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return last;
    }

    vector<int> countXInRange(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;

        for (auto query : queries) {
            int L = query[0];
            int R = query[1];
            int X = query[2];

            int start = firstOccurence(arr, L, R, X);
            int end = lastOccurence(arr, L, R, X);

            if (start == -1 || end == -1)
                ans.push_back(0);
            else
                ans.push_back(end - start + 1);
        }

        return ans;
    }
};

int main() {
    vector<int> arr = {1, 2, 2, 4, 5, 5, 5, 8};
    vector<vector<int>> queries = {
        {0, 7, 5},
        {1, 2, 2},
        {0, 3, 7}
    };

    Solution obj;
    vector<int> result = obj.countXInRange(arr, queries);

    cout << "Output: ";
    for (int x : result) {
        cout << x << " ";
    }
    return 0;
}
