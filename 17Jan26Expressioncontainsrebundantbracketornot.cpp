#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int checkRedundancy(string s) {
        stack<char> st;

        for (int i = 0; i < (int)s.size(); i++) {
            char ch = s[i];

            if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/') {
                st.push(ch);
            } else {
                // ch is either ')' or an operand (letter/number)
                if (ch == ')') {
                    bool isRedundant = true;

                    while (!st.empty() && st.top() != '(') {
                        char top = st.top();
                        if (top == '+' || top == '-' || top == '*' || top == '/') {
                            isRedundant = false;
                        }
                        st.pop();
                    }

                    if (!st.empty()) st.pop(); // pop '('

                    if (isRedundant) return 1;
                }
            }
        }
        return 0;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    getline(cin, s);

    Solution sol;
    cout << sol.checkRedundancy(s) << "\n";
    return 0;
}
