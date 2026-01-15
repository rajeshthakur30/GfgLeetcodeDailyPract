#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCandy(vector<int> &arr) {
        int n = (int)arr.size();
        if (n == 0) return 0;

        int result = 0;
        vector<int> candies(n, 1);

        // Left to right
        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }

        // Right to left
        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }

        for (int x : candies) result += x;
        return result;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    Solution obj;
    cout << obj.minCandy(arr) << "\n";
    return 0;
}
