#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll k, m, n;
    cin >> k >> m >> n;

    string win = "Barb";

    ll x = k / (m + n);

    if (x * (m + n) + m <= k) {
        win = "Alex";
    }
    cout << win << endl;
}
