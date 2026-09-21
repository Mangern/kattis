#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;

    vector<string> nums(n);
    for (auto &s : nums) {
        cin >> s;

        while (s[0] == '0')s = s.substr(1);
        for (char &c : s) {
            if (c == '9') c = '6';
        }
    }

    for (int i = 1; i < n; ++i) {
        const string& prev = nums[i-1];
        string& cur = nums[i];

        if (cur.length() < prev.length()) {
            cout << "impossible" << endl;
            return 0;
        }
        if (cur.length() > prev.length()) {
            continue;
        }

        for (char &c : cur) {
            if (c == '6')c = '9';
        }

        ll prv = stoll(prev);
        for (char &c : cur) {
            if (c == '9') {
                c = '6';

                if (stoll(cur) < prv) {
                    c = '9';
                }
            }
        }
        if (stoll(cur) < prv) {
            cout << "impossible" << endl;
            return 0;
        }
    }

    cout << "possible" << endl;
    for (auto s : nums)cout << s << '\n';
}
