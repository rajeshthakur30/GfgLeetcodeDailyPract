#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        int n = (int)arr.size();
        vector<int> ans(n, -1);
        if (n == 0) return ans;

        unordered_map<int,int> mp;
        for (int x : arr) mp[x]++;

        stack<pair<int,int>> st; // {frequency, value}

        ans[n-1] = -1;
        st.push({mp[arr[n-1]], arr[n-1]});

        for (int i = n - 2; i >= 0; i--) {
            // pop until top has strictly greater frequency
            while (!st.empty() && st.top().first <= mp[arr[i]]) {
                st.pop();
            }

            if (st.empty()) ans[i] = -1;
            else ans[i] = st.top().second;

            st.push({mp[arr[i]], arr[i]});
        }

        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution ob;
    vector<int> res = ob.nextFreqGreater(arr);

    for (int i = 0; i < (int)res.size(); i++) {
        cout << res[i] << (i + 1 == (int)res.size() ? '\n' : ' ');
    }
    return 0;
}
