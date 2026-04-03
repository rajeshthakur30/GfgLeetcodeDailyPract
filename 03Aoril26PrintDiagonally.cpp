#include <iostream>
using namespace std;

int main() {
    int n, m;
    cout << "Enter rows and columns: ";
    cin >> n >> m;

    int arr[n][m];

    cout << "Enter matrix elements:\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\nDiagonal Traversal:\n";

    // Upper diagonals (starting from first row)
    for(int col = 0; col < m; col++) {
        int i = 0;
        int j = col;

        while(i < n && j >= 0) {
            cout << arr[i][j] << " ";
            i++;
            j--;
        }
        cout << endl;
    }

    // Lower diagonals (starting from last column)
    for(int row = 1; row < n; row++) {
        int i = row;
        int j = m - 1;

        while(i < n && j >= 0) {
            cout << arr[i][j] << " ";
            i++;
            j--;
        }
        cout << endl;
    }

    return 0;
}