#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                
                int newIndex;
                
                if (i % 2 == 0) {
                    // even row → left shift
                    newIndex = (j + k) % m;
                } else {
                    // odd row → right shift
                    newIndex = (j - k % m + m) % m;
                }

                if (grid[i][j] != grid[i][newIndex]) {
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution obj;

    vector<vector<int>> grid = {
        {1, 2, 1, 2},
        {5, 5, 5, 5},
        {6, 3, 6, 3}
    };

    int k = 2;

    if (obj.areSimilar(grid, k)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}