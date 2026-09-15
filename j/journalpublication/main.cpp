#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ans;

    bool ok=1;

    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;

        vector<string> names;
        for (int j = 0; j < k; ++j) {
            string s;
            cin >> s;
            names.push_back(s);
        }
        sort(names.begin(), names.end());
        bool fail=1;
        for (const string& s : names) {
            if (ans.empty() || s >= ans.back()) {
                fail=0;
                ans.push_back(s);
                break;
            }
        }
        if (fail)ok=0;
    }
    if (!ok)cout << "impossible" << endl;
    else {
        for (auto s : ans)cout << s << endl;
    }
}
