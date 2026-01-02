#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool isp(ll x) {
    if (x <= 5) {
        return x == 2 || x == 3 || x == 5;
    }
    if (x % 2 == 0) return false;
    for (ll i = 3; i * i <= x; i += 2) {
        if (x % i == 0) return false;
    }
    return true;
}

int main() {
    ll n;
    cin >> n;

    if (!isp(n)) {
        cout << "COMPOSITE" << endl;
        return 0;
    }

    ll s = 0;
    while (n > 0) {
        s += n % 10; n /= 10;
    }
    if (!isp(s)) {
        cout << "PRIME, BUT NOT ADDITIVE" << endl;
    } else cout << "ADDITIVE PRIME" << endl;
}
