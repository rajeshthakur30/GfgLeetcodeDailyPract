#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> flipSquareSubmatrix(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();

    // Traverse all k x k submatrices
    for (int i = 0; i <= n - k; i++) {
        for (int j = 0; j <= m - k; j++) {

            // Flip vertically inside submatrix
            for (int x = 0; x < k / 2; x++) {
                for (int y = 0; y < k; y++) {
                    // Swap top and bottom rows
                    swap(grid[i + x][j + y], grid[i + k - 1 - x][j + y]);
                }
            }

        }
    }

    return grid;
}

int main() {
    vector<vector<int>> grid = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int k = 2;

    vector<vector<int>> result = flipSquareSubmatrix(grid, k);

    // Print result
    for (auto& row : result) {
        for (auto& val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}