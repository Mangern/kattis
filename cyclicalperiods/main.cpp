#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    map<char, ll> pos;

    ll maxl = 0;
    char maxc = 0;
    for (int i = 0; i < n; ++i) {
        ll p; string s;
        cin >> p >> s;
        for (char c : s) {
            if (pos.count(c)) {
                if (p - pos[c] > maxl) {
                    maxl = p - pos[c];
                    maxc = c;
                }
            }
            pos[c] = p;
        }
    }

    cout << maxc << endl;
}
