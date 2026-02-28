#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int A[] = {1, 4, 5, 7};
    int B[] = {10, 20, 30, 40};

    int n = 4;
    int m = 4;

    int x = 32;

    int minDiff = 100000;
    int a = 0, b = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int sum = A[i] + B[j];
            int diff = abs(sum - x);

            if (diff < minDiff)
            {
                minDiff = diff;
                a = A[i];
                b = B[j];
            }
        }
    }

    cout << "Closest pair is: ";
    cout << a << " and " << b << endl;

    cout << "Sum = " << a + b << endl;

    return 0;
}