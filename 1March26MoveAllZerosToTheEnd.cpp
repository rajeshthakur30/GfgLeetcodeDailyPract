#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n)
{
    int j = 0; // position for non-zero

    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int main()
{
    int arr[] = {0, 1, 0, 3, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    moveZeroes(arr, n);

    cout << "After moving zeroes: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}