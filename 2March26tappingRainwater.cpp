#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWater(vector<int> &arr) {
        
        int n = arr.size();
        
        if (n == 0) return 0;

        vector<int> Leftmax(n), Rightmax(n);

        // Left max
        Leftmax[0] = arr[0];
        for (int i = 1; i < n; i++) {
            Leftmax[i] = max(Leftmax[i - 1], arr[i]);
        }

        // Right max
        Rightmax[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            Rightmax[i] = max(Rightmax[i + 1], arr[i]);
        }

        int water = 0;

        for (int i = 0; i < n; i++) {
            int miniheight = min(Leftmax[i], Rightmax[i]);
            water += miniheight - arr[i];
        }

        return water;
    }
};

int main() {

    Solution obj;

    vector<int> arr = {3, 0, 2, 0, 4};

    cout << "Water stored = " << obj.maxWater(arr);

    return 0;
}