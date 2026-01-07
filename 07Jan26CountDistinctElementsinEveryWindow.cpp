#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        vector<int> res;
        unordered_map<int, int> mp;

        int n = arr.size();
        if (k > n) return res;

        // First window
        for (int i = 0; i < k; i++) {
            mp[arr[i]]++;
        }
        res.push_back(mp.size());

        // Sliding window
        int j = 0;
        for (int i = k; i < n; i++) {
            mp[arr[j]]--;
            if (mp[arr[j]] == 0)
                mp.erase(arr[j]);
            j++;

            mp[arr[i]]++;
            res.push_back(mp.size());
        }
        return res;
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
    vector<int> ans = obj.countDistinct(arr, k);

    for (int x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
