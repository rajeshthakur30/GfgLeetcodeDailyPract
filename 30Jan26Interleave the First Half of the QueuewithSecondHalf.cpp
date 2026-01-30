#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    void rearrangeQueue(queue<int> &q) {
        queue<int> q1, q2;
        int n = q.size();

        // Move first half into q1
        for (int i = 0; i < (n + 1) / 2; i++) {
            q1.push(q.front());
            q.pop();
        }

        // Move remaining into q2
        while (!q.empty()) {
            q2.push(q.front());
            q.pop();
        }

        // Interleave elements
        while (!q1.empty() && !q2.empty()) {
            q.push(q1.front());
            q.push(q2.front());
            q1.pop();
            q2.pop();
        }

        // If q1 has one extra element (odd size case)
        if (!q1.empty()) {
            q.push(q1.front());
        }
    }
};

int main() {
    queue<int> q;
    int n, x;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter queue elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> x;
        q.push(x);
    }

    Solution obj;
    obj.rearrangeQueue(q);

    cout << "Rearranged Queue:\n";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
