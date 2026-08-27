#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, q;
    cin >> n >> q;
    vector<ll> p(1,0);
    vector<ll> a(n);
    for (auto &x : a) cin >> x;
    sort(begin(a),end(a));
    for (auto x : a)p.push_back(p.back()+x);
    while (q-->0) {
        ll m;
        cin >> m;
        cout << p[m] << endl;
    }
}
