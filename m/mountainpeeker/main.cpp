#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

int main() {
    int n;
    cin >> n;

    set<ii> pk;
    ll h;
    cin >> h;
    pk.insert({0,h});

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        pk.insert({x,y});
    }

    auto start = pk.find({0,h});

    auto it = start;

    ll yv = -1e6;
    ll xv = -1;
    int ans=0;
    while (it != begin(pk)) {
        it = prev(it);
        auto [x, y] = *it;
        if (xv * (y - h) < x * (yv - h)) {
            ++ans;
            xv = x;
            yv = y;
        }
    }

    it = next(start);
    yv = -1e6;
    xv = 1;

    while (it != end(pk)) {
        auto [x, y] = *it;
        if (xv * (y - h) > x * (yv - h)) {
            ++ans;
            xv = x;
            yv = y;
        }
        it = next(it);
    }

    cout << ans << endl;
}
