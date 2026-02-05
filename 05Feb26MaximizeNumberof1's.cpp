#include <bits/stdc++.h>
using namespace std;

int maxOnes(int arr[], int n, int m) {
    int left = 0, zeroCount = 0, ans = 0;

    for (int right = 0; right < n; right++) {
        if (arr[right] == 0)
            zeroCount++;

        while (zeroCount > m) {
            if (arr[left] == 0)
                zeroCount--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    int n, m;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter binary array elements (0/1): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter number of flips allowed (m): ";
    cin >> m;

    cout << "Maximum number of consecutive 1's = "
         << maxOnes(arr, n, m) << endl;

    return 0;
}
