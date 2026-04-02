#include<iostream>
using namespace std;

int numberOfWays(int n, int k) {
    // Base cases
    if(n == 1) return k;
    if(n == 2) return k * k;

    int same = k;            // for n=2 → same = k
    int diff = k * (k - 1);  // for n=2 → diff = k*(k-1)

    for(int i = 3; i <= n; i++) {
        int newSame = diff;
        int newDiff = (same + diff) * (k - 1);

        same = newSame;
        diff = newDiff;
    }

    return same + diff;
}

int main() {
    int n, k;
    cout << "Enter number of posts: ";
    cin >> n;

    cout << "Enter number of colors: ";
    cin >> k;

    cout << "Total ways to paint fence: " << numberOfWays(n, k);

    return 0;
}