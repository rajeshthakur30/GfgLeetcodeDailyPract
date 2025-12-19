#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to rotate an array by d elements in counter-clockwise direction.
    void rotateArr(vector<int>& arr, int d) {
        int n = arr.size();
        d = d % n;   // Handle case when d > n

        reverse(arr.begin(), arr.begin() + d);
        reverse(arr.begin() + d, arr.end());
        reverse(arr.begin(), arr.end());
    }
};

int main() {
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 2;

    Solution obj;
    obj.rotateArr(arr, d);

    for (int x : arr)
        cout << x << " ";

    return 0;
}
