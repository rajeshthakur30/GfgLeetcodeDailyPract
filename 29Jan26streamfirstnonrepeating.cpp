#include <bits/stdc++.h>
using namespace std;

int main() {
    string stream;
    cout << "Enter character stream: ";
    cin >> stream;

    vector<int> freq(26, 0);
    queue<char> q;

    for(char ch : stream) {
        // increase frequency
        freq[ch - 'a']++;

        // push into queue
        q.push(ch);

        // remove repeating characters from front
        while(!q.empty() && freq[q.front() - 'a'] > 1) {
            q.pop();
        }

        // print result
        if(q.empty())
            cout << "-1 ";
        else
            cout << q.front() << " ";
    }

    return 0;
}
