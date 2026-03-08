#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool checkTriplet(vector<int>& arr) {
    int n = arr.size();

    // Square all elements
    for(int i = 0; i < n; i++)
        arr[i] = arr[i] * arr[i];

    // Sort the array
    sort(arr.begin(), arr.end());

    // Fix one element and use two pointer
    for(int i = n - 1; i >= 2; i--) {
        int left = 0;
        int right = i - 1;

        while(left < right) {
            if(arr[left] + arr[right] == arr[i])
                return true;
            else if(arr[left] + arr[right] < arr[i])
                left++;
            else
                right--;
        }
    }

    return false;
}

int main() {
    vector<int> arr = {3, 1, 4, 6, 5};

    if(checkTriplet(arr))
        cout << "Pythagorean Triplet Exists";
    else
        cout << "No Pythagorean Triplet";

    return 0;
}