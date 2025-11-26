#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 3>;

int main() {
    int n;
    cin >> n;

    auto acmp = [](const ii &a, const ii &b) {
        if (a[0] == b[0] && a[1] == b[1])return a[2] < b[2];
        if (a[0] == b[0])return a[1] > b[1];
        return a[0] < b[0];
    };
    auto bcmp = [](const ii &a, const ii &b) {
        if (a[0] == b[0] && a[1] == b[1])return a[2] < b[2];
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] > b[1];
    };

    set<ii, decltype(acmp)> aset(acmp);
    set<ii, decltype(bcmp)> bset(bcmp);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        string t;
        for (char c : s) {
            if (c == '(') {
                t.push_back(c);
            } else {
                if (t.size() > 0 && t.back() == '(') {
                    t.pop_back();
                } else {
                    t.push_back(c);
                }
            }
        }

        int a = 0, b = 0;
        for (char c : t) {
            if (c == '(')++b;
            else ++a;
        }
        bset.insert({a,b,i});
    }
    int bsum = 0;

    vector<int> ans(n);

    for (int i = 0; i < n; ++i) {
        while (bset.size() && (*bset.begin())[0] > bsum) {
            aset.insert(*bset.begin());
            bset.erase(bset.begin());
        }
        while (aset.size() && (*aset.begin())[0] <= bsum) {
            bset.insert(*aset.begin());
            aset.erase(aset.begin());
        }

        if (bset.empty()) {
            cout << "impossible" << endl;
            return 0;
        }

        auto [a,b,idx] = *bset.begin();
        bset.erase(bset.begin());
        ans[i] = idx+1;
        bsum -= a;
        bsum += b;
    }

    if (bsum > 0) {
        cout << "impossible" << endl;
        return 0;
    }

    for (auto x : ans) cout << x << endl;
}
