#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st; // stores indexes of previous greater element

        for(int i = 0; i < n; i++) {
            // pop until we get a strictly greater element on left
            while(!st.empty() && arr[st.top()] <= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i] = i + 1;          // no greater on left
            } else {
                ans[i] = i - st.top();   // distance from previous greater
            }

            st.push(i);
        }
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];

        Solution obj;
        vector<int> res = obj.calculateSpan(arr);

        for(int x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
