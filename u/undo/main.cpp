#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    string ret;

    stack<pair<int, char>> ops;

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        if (s == "Undo") {
            if (ops.empty()) continue;

            auto [t, c] = ops.top();
            ops.pop();

            if (t == 0) {
                ret.pop_back();
            } else {
                ret.push_back(c);
            }
        } else if (s == "Backspace") {
            if (ret.empty()) continue;

            char c =ret.back();
            ret.pop_back();

            ops.push({1, c});
        } else {
            char c = s[0];
            ret.push_back(c);
            ops.push({0, c});
        }
    }

    cout << ret << ">" << endl;
}
