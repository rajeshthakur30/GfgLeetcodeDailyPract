#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        if(n == 0) return 0;

        unordered_map<int,int> m;
        int start = 0;
        int end = 0;
        int ans = 0;

        while(end < n) {
            // Add current element
            m[arr[end]]++;

            // If more than 2 distinct elements, shrink window
            while(m.size() > 2) {
                m[arr[start]]--;
                if(m[arr[start]] == 0) {
                    m.erase(arr[start]);
                }
                start++;
            }

            // Update answer
            ans = max(ans, end - start + 1);

            end++;
        }

        return ans;
    }
};

int main() {
    Solution obj;
    vector<int> arr = {1, 2, 1, 2, 3, 2, 2};
    
    cout << "Maximum length of subarray with at most 2 distinct elements: ";
    cout << obj.totalElements(arr) << endl;

    return 0;
}