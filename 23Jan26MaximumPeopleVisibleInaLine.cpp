#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int maxPeople(vector<int> &arr) {
        int n = arr.size();
        stack<int> st;

        // ng[i] = index of next greater/equal element, if none then n
        // pg[i] = index of previous greater/equal element, if none then -1
        vector<int> ng(n, n), pg(n, -1);

        // --------- Next Greater (or Equal) to the right ----------
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                ng[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // clear stack
        while (!st.empty()) st.pop();

        // --------- Previous Greater (or Equal) to the left ----------
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[i] >= arr[st.top()]) {
                pg[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        // --------- Calculate maximum range ----------
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, ng[i] - pg[i] - 1);
        }

        return ans;
    }
};
