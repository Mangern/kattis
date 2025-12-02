#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

int main() {
    int n;
    cin >> n;

    vector<ii> a(n);
    for (auto &[x,y] : a)cin >> x >> y;

    sort(begin(a), end(a), [](auto x, auto y) {
        if (x[1] == y[1]) return x[0]>y[0];
        return x[1] < y[1];
    });

    ll ans = 0;
    ll tot = 0;
    priority_queue<ll> pq;
    for (auto [t, s] : a) {
        pq.push(t);
        tot += t;
        while (tot > s) {
            ll x = pq.top();
            pq.pop();
            pq.push(x/2);
            tot -= x;
            tot += x/2;
            ++ans;
        }
    }
    cout << ans << endl;
}
