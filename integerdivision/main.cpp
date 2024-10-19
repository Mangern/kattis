#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
using vll = vector<ll>;

ll cnt(vll& a) {
    map<ll,ll> cnts;
    for (auto x : a)++cnts[x];

    ll ret = 0;
    for (auto [k, v] : cnts)ret += (v * (v - 1)) / 2;
    return ret;
}

int main() {
    ll n, d;
    cin >> n >> d;

    vll a(n);
    for (auto& x : a) {cin >> x; x/=d;}

    cout << cnt(a) << endl;
}
