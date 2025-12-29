#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        vector<int> mergedArr;

        // Add elements of first array
        for (int i = 0; i < a.size(); i++) {
            mergedArr.push_back(a[i]);
        }

        // Add elements of second array
        for (int i = 0; i < b.size(); i++) {
            mergedArr.push_back(b[i]);
        }

        // Sort the merged array
        sort(mergedArr.begin(), mergedArr.end());

        // Return k-th element (1-based indexing)
        return mergedArr[k - 1];
    }
};

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};
    int k = 5;

    Solution obj;
    cout << "K-th element is: " << obj.kthElement(a, b, k);

    return 0;
}
