#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int catchThieves(vector<char> &arr, int k) {
        int n = (int)arr.size();
        int i = 0, j = 0, cnt = 0;   // i -> police, j -> thief

        while (i < n && j < n) {
            while (i < n && arr[i] != 'P') i++;
            while (j < n && arr[j] != 'T') j++;

            if (i == n || j == n) break;

            if (abs(i - j) <= k) {
                cnt++;
                i++;
                j++;
            } else if (j < i) {
                j++;   // move thief forward
            } else {
                i++;   // move police forward
            }
        }
        return cnt;
    }
};

int main() {
    int n, k;
    cin >> n >> k;

    vector<char> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // input like: P T T P ...
    }

    Solution obj;
    cout << obj.catchThieves(arr, k) << "\n";
    return 0;
}
