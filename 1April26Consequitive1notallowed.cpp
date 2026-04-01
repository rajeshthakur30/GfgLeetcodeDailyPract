#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countStrings(int n) {
        // Base cases
        if(n == 1) return 2;

        int x = 1, y = 2;

        for(int i = 2; i <= n; i++){
            int z = x + y;
            x = y;
            y = z;
        }
        return y;
    }
};

int main() {
    int t;
    cin >> t;   // number of test cases

    while(t--) {
        int n;
        cin >> n;

        Solution obj;
        cout << obj.countStrings(n) << endl;
    }

    return 0;
}