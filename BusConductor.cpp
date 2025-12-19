#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMoves(vector<int>& chairs, vector<int>& passengers) {
        int n = chairs.size();

        sort(chairs.begin(), chairs.end());
        sort(passengers.begin(), passengers.end());

        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += abs(chairs[i] - passengers[i]);
        }
        return sum;
    }
};

int main() {
    vector<int> chairs = {3, 1, 5};
    vector<int> passengers = {2, 7, 4};

    Solution obj;
    cout << "Minimum moves = " << obj.findMoves(chairs, passengers) << endl;

    return 0;
}
