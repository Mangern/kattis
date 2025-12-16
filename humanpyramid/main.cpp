#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    cin >> n;

    ll t = 1;
    while (t * (t + 1) / 2 <= n) {
        ++t;
    }
    cout << t-1 << endl;
}
