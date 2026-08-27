#include <bits/stdc++.h>
using namespace std;
using ll = long long;

char has[505];

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for (auto &s : arr) cin >> s;

    for (ll m = n; ; ++m) {
        ll best = -1;
        for (ll a = 1; a <= m; ++a) {
            memset(has, 0, sizeof has);
            bool ok = 1;
            for (const string &s: arr) {
                ll hash = 0;
                for (char c : s) {
                    hash = (a * hash + c) % m;
                }
                if (has[hash]) {
                    ok = false;
                    break;
                }
                has[hash] = 1;
            }
            if (ok) {
                cout << a << " " << m << endl;
                return 0;
            }
        }
    }
}
