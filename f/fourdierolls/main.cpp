#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

ii search(vector<ll> &v) {
    if (v.size() == 4) {
        ll a = 0;
        ll b = 0;
        bool f=0;
        for (int i = 0; i < 4; ++i) {
            for (int j = i + 1; j < 4; ++j) {
                if (v[i] == v[j]) {
                    f=1;
                    break;
                }
            }
        }
        a += !f;
        b += f;
        return {a,b};
    }

    ll a = 0;
    ll b = 0;
    for (int i = 1; i <= 6; ++i) {
        v.push_back(i);
        auto [x, y] = search(v);
        v.pop_back();
        a+=x;
        b+=y;
    }
    return {a,b};
}

int main() {
    vector<ll> nums;
    ll n;
    cin >> n;
    for (ll i = 0; i < n; ++i) {
        ll x;
        cin >> x;
        nums.push_back(x);
    }
    auto [a, b] = search(nums);
    cout << a << " " << b << endl;
}
