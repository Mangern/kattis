#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using line_t = array<ll,3>;

line_t line(ll x1, ll y1, ll x2, ll y2) {
    // a = (x2 - x1) / (y1 - y2);
    // b = - (x1+x2)/2 - a/2*(y1 + y2);
    // x + (x2 - x1) / (y1 - y2) * y - (x1+x2)/2 - a/2*(y1 + y2) == 0
    // 2x + 2*(x2-x1)/(y1-y2) * y - (x1+x2) - a*(y1+y2) == 0
    // 2*(y1-y2) * x + 2 * (x2-x1) * y - (y1-y2)*(x1+x2) - a * (y1 - y2)*(y1+y2) == 0
    // 2*(y1-y2) * x + 2*(x2-x1) * y - (y1-y2)*(x1+x2) - (x2-x1)*(y1+y2) == 0
    ll a = 2*(y1-y2);
    ll b =  2*(x2-x1); 
    ll c = -(y1-y2)*(x1+x2) - (x2-x1)*(y1+y2);
    if (a < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
    }
    if (a == 0 && b < 0) {
        b *= -1;
        c *= -1;
    }
    ll g = gcd(a,gcd(b,c));
    a /= g;
    b /= g;
    c /= g;
    return {a,b,c};
}

int main() {
    ll x1, x2, y1, y2;

    cin >> x1 >> y1 >> x2 >> y2;

    auto l1 = line(x1,y1,x2,y2);
    int n;
    cin >> n;

    while (n-->0) {
        cin >> x1 >> y1 >> x2 >> y2;

        auto l2 = line(x1,y1,x2,y2);

        if (l1[0] == l2[0] && l1[1] == l2[1]) {
            cout << "NO" << endl;
        } else cout << "YES" << endl;
    }
}
