#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int countLessEqual(vector<int>& arr, int x) {
        int count = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= x) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {1, 3, 5, 7, 9};
    int x = 5;

    int result = obj.countLessEqual(arr, x);
    cout << "Count of elements <= " << x << " is: " << result << endl;

    return 0;
}
