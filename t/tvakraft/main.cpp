#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll x;
    cin >> x;
    if (__builtin_popcountll(x) == 1) {
        cout << "Yes" << endl;
    } else cout << "No" << endl;
}
