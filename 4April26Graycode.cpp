#include <iostream>
#include <vector>
using namespace std;

vector<int> grayCode(int n) {
    vector<int> result;
    
    int total = 1 << n;  // 2^n combinations
    
    for(int i = 0; i < total; i++) {
        result.push_back(i ^ (i >> 1));
    }
    
    return result;
}

int main() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;

    vector<int> res = grayCode(n);

    cout << "Gray Code sequence:\n";
    for(int num : res) {
        cout << num << " ";
    }

    return 0;
}