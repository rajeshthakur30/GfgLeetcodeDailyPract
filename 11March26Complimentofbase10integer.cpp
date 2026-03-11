#include <iostream>
using namespace std;

class Solution {
public:
    int bitwiseComplement(int n) {
        int m = n;
        int mask = 0;

        if (m == 0) 
            return 1;

        // create mask like 111... depending on number of bits
        while (m != 0) {
            mask = (mask << 1) | 1;
            m = m >> 1;
        }

        int ans = (~n) & mask;
        return ans;
    }
};

int main() {
    Solution obj;
    int n;

    cout << "Enter a number: ";
    cin >> n;

    int result = obj.bitwiseComplement(n);

    cout << "Bitwise Complement of " << n << " is: " << result << endl;

    return 0;
}