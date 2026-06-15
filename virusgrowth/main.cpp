#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll a = 0;
    ll b = 1;

    ll t;

    for (t = 0; a < n; ++t) {
        // a, b = b, a + b

        a += b;
        swap(a,b);
    }

    cout << t << endl;
}
