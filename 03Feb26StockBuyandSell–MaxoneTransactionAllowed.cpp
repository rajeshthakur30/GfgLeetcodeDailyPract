#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int profit = 0;
        int mini = INT_MAX;

        for (int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
            int currProfit = prices[i] - mini;
            profit = max(profit, currProfit);
        }
        return profit;
    }
};

int main() {
    int n;
    cin >> n;              // number of days

    vector<int> prices(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];  // stock prices
    }

    Solution obj;
    cout << obj.maxProfit(prices);

    return 0;
}
