#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll score(const string& s) {
    for (int pl = 1; pl <= s.length(); ++pl) {
        if (s.length() % pl != 0) continue;
        bool ok=1;
        for (int i = 0; i < s.length(); i += pl) {
            for (int j = i; j < i + pl; ++j) {
                if (s[j] != s[j-i]) {
                    ok=0;
                    break;
                }
            }
        }
        if (ok) return (ll)pl;
    }
    assert(false);
}

int main() {
    ll n;
    cin >> n;
    vector<ll> v1, v2;
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v1.push_back(score(s));
    }
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        v2.push_back(score(s));
    }
    sort(begin(v1),end(v1));
    sort(begin(v2),end(v2));
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (v1[i] - v2[i]) * (v1[i] - v2[i]);
    }
    cout << ans << endl;
}
