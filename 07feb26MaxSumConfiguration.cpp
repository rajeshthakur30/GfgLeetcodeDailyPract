#include <iostream>
using namespace std;

int maxSum(int arr[], int n) {
    int arrSum = 0, currVal = 0;

    // Initial sums
    for (int i = 0; i < n; i++) {
        arrSum += arr[i];
        currVal += i * arr[i];
    }

    int maxVal = currVal;

    // Try all rotations
    for (int j = 1; j < n; j++) {
        currVal = currVal + arrSum - n * arr[n - j];
        maxVal = max(maxVal, currVal);
    }

    return maxVal;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSum(arr, n);

    return 0;
}
