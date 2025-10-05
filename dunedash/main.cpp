//#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using arr = array<ll, 2>;
using arrr = array<ll, 3>;
using vi = vector<int>;
using vll = vector<ll>;
#define FORMASK(i, mask) for (int _x = (mask), i; i = 31-__builtin_clz(_x&(-_x)), _x; _x -= (_x&-_x))


ll dist(const arr &a, const arr &b) {
    return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
}

ll n;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    vector<arr> pts(n - 1);

    arr first;
    cin >> first[0] >> first[1];

    for (auto &pp : pts) {
        cin >> pp[0] >> pp[1];
    }

    sort(begin(pts), end(pts), [&] (auto a, auto b) {
        return dist(a, first) < dist(b, first);
    });

    arr ep = pts.back();
    pts.pop_back();
    pts.push_back(first);

    sort(begin(pts), end(pts), [&] (auto a, auto b) {
        return dist(a, ep) < dist(b, ep);
    });

    long double ans = 0.0;

    for (auto p : pts) {
        ll d = dist(p, ep);

        ans += sqrtl(d);

        ep = p;
    }

    cout << setprecision(18) << fixed << ans << endl;
}
