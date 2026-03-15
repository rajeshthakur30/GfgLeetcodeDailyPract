#include <bits/stdc++.h>
using namespace std;

class Fancy {
public:
    const long long MOD = 1000000007;
    vector<long long> arr;
    long long mul = 1;
    long long add = 0;

    long long modInverse(long long a) {
        long long res = 1;
        long long power = MOD - 2;

        while (power > 0) {
            if (power % 2 == 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            power /= 2;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = (val - add + MOD) % MOD;
        x = (x * modInverse(mul)) % MOD;
        arr.push_back(x);
    }

    void addAll(int inc) {
        add = (add + inc) % MOD;
    }

    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }

    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul % MOD + add) % MOD;
    }
};

int main() {
    Fancy fancy;

    fancy.append(2);     
    fancy.addAll(3);     
    fancy.append(7);     
    fancy.multAll(2);    

    cout << fancy.getIndex(0) << endl; // expected output: 10
    fancy.addAll(3);
    fancy.append(10);

    cout << fancy.getIndex(0) << endl;
    cout << fancy.getIndex(1) << endl;
    cout << fancy.getIndex(2) << endl;

    return 0;
}