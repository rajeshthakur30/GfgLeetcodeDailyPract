#include <bits/stdc++.h>
using namespace std;

void permute(int idx, vector<int> &a) {
    int n = a.size();
    if (idx == n) {
        for (int x : a) cout << x << " ";
        cout << "\n";
        return;
    }

    for (int i = idx; i < n; i++) {
        swap(a[idx], a[i]);
        permute(idx + 1, a);
        swap(a[idx], a[i]); // backtrack
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    permute(0, a);
    return 0;
}
