#include <iostream>
#include <vector>
using namespace std;

int rowWithMax1s(vector<vector<int>> &arr) {
    int n = arr.size();
    int m = arr[0].size();

    for (int col = 0; col < m; col++) {
        for (int row = 0; row < n; row++) {
            if (arr[row][col] == 1) {
                return row;
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> arr = {
        {0, 0, 1, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 1}
    };

    cout << "Row with max 1s: " << rowWithMax1s(arr);
    return 0;
}
