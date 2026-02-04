#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxtime = 0;

        // ants moving left
        for (int i = 0; i < left.size(); i++) {
            maxtime = max(maxtime, left[i]);
        }

        // ants moving right
        for (int i = 0; i < right.size(); i++) {
            maxtime = max(maxtime, n - right[i]);
        }

        return maxtime;
    }
};

int main() {
    int n;
    cin >> n;

    int l;
    cin >> l;
    vector<int> left(l);
    for (int i = 0; i < l; i++) {
        cin >> left[i];
    }

    int r;
    cin >> r;
    vector<int> right(r);
    for (int i = 0; i < r; i++) {
        cin >> right[i];
    }

    Solution obj;
    cout << obj.getLastMoment(n, left, right);

    return 0;
}
