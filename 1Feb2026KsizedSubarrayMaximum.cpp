#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    deque<int> dq;        // stores indices
    vector<int> result;

    for(int i = 0; i < n; i++) {

        // 1️⃣ Remove elements outside the window
        if(!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }

        // 2️⃣ Remove smaller elements from back
        while(!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }

        // 3️⃣ Add current index
        dq.push_back(i);

        // 4️⃣ Store result when window size >= k
        if(i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }

    // Output result
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}
