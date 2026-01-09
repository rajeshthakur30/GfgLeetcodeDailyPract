#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        int i = 0;
        int cnt = 0;

        for (int j = 0; j < arr.size(); j++) {
            mp[arr[j]]++;

            // Shrink window if distinct elements > k
            while (mp.size() > k) {
                mp[arr[i]]--;
                if (mp[arr[i]] == 0)
                    mp.erase(arr[i]);
                i++;
            }

            // Count subarrays ending at j
            cnt += (j - i + 1);
        }
        return cnt;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << obj.countAtMostK(arr, k) << endl;

    return 0;
}
