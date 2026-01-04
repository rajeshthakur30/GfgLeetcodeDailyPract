#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sort012(vector<int>& arr) {
        int s = 0;                 // start pointer
        int e = 0;                 // current pointer
        int n = arr.size() - 1;    // end pointer

        while (e <= n) {
            if (arr[e] == 0) {
                swap(arr[e], arr[s]);
                s++;
                e++;
            }
            else if (arr[e] == 1) {
                e++;
            }
            else { // arr[e] == 2
                swap(arr[e], arr[n]);
                n--;
            }
        }
    }
};

int main() {
    Solution obj;

    vector<int> arr = {0, 2, 1, 2, 0, 1};

    cout << "Before sorting: ";
    for (int x : arr) {
        cout << x << " ";
    }

    obj.sort012(arr);

    cout << "\nAfter sorting: ";
    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}
