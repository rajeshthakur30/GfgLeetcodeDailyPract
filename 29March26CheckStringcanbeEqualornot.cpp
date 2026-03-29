#include <iostream>
#include <algorithm>
using namespace std;

bool canBeEqual(string s1, string s2) {
    // Sort group (0,2)
    string a1 = "";
    a1 += s1[0];
    a1 += s1[2];
    
    string b1 = "";
    b1 += s2[0];
    b1 += s2[2];
    
    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());

    // Sort group (1,3)
    string a2 = "";
    a2 += s1[1];
    a2 += s1[3];
    
    string b2 = "";
    b2 += s2[1];
    b2 += s2[3];
    
    sort(a2.begin(), a2.end());
    sort(b2.begin(), b2.end());

    return (a1 == b1) && (a2 == b2);
}

int main() {
    string s1 = "abcd";
    string s2 = "cdab";

    if (canBeEqual(s1, s2)) {
        cout << "True" << endl;
    } else {
        cout << "False" << endl;
    }

    return 0;
}