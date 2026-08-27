#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;

const ll M = 10001;
vll mroot[M];


ll mod(ll x) {
    return ((x%M)+M)%M;
}

vll xs;
vll as;

ll iter(ll x, ll a, ll b) {
    return mod(mod(x*a)+b);
}

int main() {

    int n;
    cin >> n;
    if (n == 1) {
        int x;
        cin >> x;
        cout << x << endl;
        return 0;
    }

    xs = vll(n);
    for (auto& x : xs)cin >> x;

    ll ra = -1, rb = -1;
    for (ll a = 0; a < M; ++a) {
        for (ll b = 0; b < M; ++b) {
            bool f = 0;
            for (int idx = 1; idx < n; ++idx) {

                if (iter(iter(xs[idx-1],a,b),a,b) != xs[idx]) {
                    f = 1;
                    break;
                }
            }

            if (!f) {
                ra = a;
                rb = b;
                break;
            }
        }
        if (ra != -1)break;
    }
    //cout << ra << " " << rb << endl;

    ll p = xs[0];

    for (int i = 0; i < 2*n; ++i) {
        //cout << p << " ";
        p = mod(p*ra+rb);
    }
    //cout << endl;

    for (auto x : xs) {
        cout << mod(x*ra+rb) << endl;
    }
}
