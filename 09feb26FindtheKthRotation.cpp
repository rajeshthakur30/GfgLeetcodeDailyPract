#include <iostream>
using namespace std;

int main() {
    int arr[] = {1,2,3,4,5};
    int n = 5, k = 2;

    k = k % n;
    
    for(int i=k;i<n;i++)
        cout << arr[i] << " ";
    for(int i=0;i<k;i++)
        cout << arr[i] << " ";

    return 0;
}
