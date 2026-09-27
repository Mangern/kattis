#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;
    string s;
    cin >> s;

    ll l = 0; 
    ll r = 0;
    ll sm = 0;

    ll mind = m + 5;

    for (; l < m; ++l) {
        while (r < m && sm < n) {
            sm += s[r] - '0';
            ++r;
        }

        if (sm < n) {
            break;
        }

        mind = min(mind, r - l - 1);

        sm -= s[l] - '0';
    }

    if (mind == m + 5) cout << "impossible" << endl;
    else cout << mind << endl;
}
