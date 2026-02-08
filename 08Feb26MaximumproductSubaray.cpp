#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int> &arr) {
        int product = 1;
        int maxiProduct = INT_MIN;

        // Left to right
        for (int i = 0; i < arr.size(); i++) {
            product *= arr[i];
            maxiProduct = max(maxiProduct, product);
            if (product == 0) product = 1;
        }

        // Right to left
        product = 1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            product *= arr[i];
            maxiProduct = max(maxiProduct, product);
            if (product == 0) product = 1;
        }

        return maxiProduct;
    }
};

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    Solution obj;
    cout << "Maximum Product Subarray = "
         << obj.maxProduct(arr);

    return 0;
}
