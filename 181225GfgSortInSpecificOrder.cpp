#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 2, 3, 5, 4, 7, 10};
    
    vector<int> even, odd;

    // Separate even and odd numbers
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0)
            even.push_back(arr[i]);
        else
            odd.push_back(arr[i]);
    }

    // Sort odd in descending order
    sort(odd.begin(), odd.end(), greater<int>());

    // Sort even in ascending order
    sort(even.begin(), even.end());

    // Merge back into arr
    int index = 0;
    for (int x : odd)
        arr[index++] = x;

    for (int x : even)
        arr[index++] = x;

    // Print output
    for (int x : arr)
        cout << x << " ";

    return 0;
}
