#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int ans = 0;

    // Precompute max element to the right of each j
    vector<int> rightMax(n, 0);
    rightMax[n-1] = arr[n-1];
    for (int i = n-2; i >= 0; i--)
        rightMax[i] = max(arr[i], rightMax[i+1]);

    int leftMax = arr[0];

    for (int j = 1; j < n-1; j++) {
        if (leftMax > arr[j] && rightMax[j+1] > 0) {
            ans = max(ans, (leftMax - arr[j]) * rightMax[j+1]);
        }
        leftMax = max(leftMax, arr[j]);
    }

    cout << ans << endl;
    return 0;
}
