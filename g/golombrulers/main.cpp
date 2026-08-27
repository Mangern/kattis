#include <algorithm>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string line;
    while (getline(cin, line)) {
        stringstream ss(line);
        vector<int> nums;
        int x;

        while (ss >> x) {
            nums.push_back(x);
        }
        sort(nums.begin(), nums.end());

        int n = nums.back();

        multiset<int> ms;
        set<int> s;

        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                ms.insert(nums[j] - nums[i]);
                s.insert(nums[j] - nums[i]);
            }
        }
        if (s.size() != ms.size()) {
            cout << "not a ruler" << endl;
        } else if (s.size() != n) {
            cout << "missing";

            for (int i = 1; i <= n; ++i) {
                if (!s.count(i))cout << " " << i;
            }
            cout << endl;
        } else {
            cout << "perfect" << endl;
        }
    }
}
