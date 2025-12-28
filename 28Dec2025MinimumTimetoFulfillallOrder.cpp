#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(vector<int>& ranks, int n) {
        long long low = 0;
        long long high = 1e9;
        long long ans = high;

        while (low <= high) {
            long long mid = (low + high) / 2;
            long long count = 0;

            for (int r : ranks) {
                // Using quadratic formula:
                // r * p * (p + 1) / 2 <= mid
                long long p = (-r + sqrt((long double)r * r + 8LL * r * mid)) / (2 * r);
                if (p > 0) count += p;
            }

            if (count >= n) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    int k, n;
    cout << "Enter number of cooks: ";
    cin >> k;

    vector<int> ranks(k);
    cout << "Enter ranks of cooks:\n";
    for (int i = 0; i < k; i++) {
        cin >> ranks[i];
    }

    cout << "Enter number of orders: ";
    cin >> n;

    Solution obj;
    cout << "Minimum time to fulfil all orders: ";
    cout << obj.minTime(ranks, n) << endl;

    return 0;
}
