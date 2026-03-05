#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
int minOperations(string s) {
int count = 0;
int n = s.length();


    for (int i = 0; i < n; i++) {
        count += (s[i] ^ i) & 1;
    }

    return min(count, n - count);
  }

};

int main() {
Solution obj;
string s;
cout << "Enter binary string: ";
cin >> s;

int result = obj.minOperations(s);

cout << "Minimum operations required: " << result << endl;

return 0;

}
