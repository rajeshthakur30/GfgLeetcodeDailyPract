#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // Given array
    vector<int> arr = {1, 4, 2, 8, 5};

    // Given queries
    vector<vector<int>> queries = {{1, 4}, {3, 6}, {0, 10}};

    // Step 1: sort the array
    sort(arr.begin(), arr.end());

    // Step 2: process each query
    for (auto &q : queries) {
        int L = q[0];
        int R = q[1];

        int leftIndex = lower_bound(arr.begin(), arr.end(), L) - arr.begin();
        int rightIndex = upper_bound(arr.begin(), arr.end(), R) - arr.begin();

        cout << rightIndex - leftIndex << " ";
    }

    return 0;
}
