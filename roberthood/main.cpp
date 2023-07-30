#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;
using ld = long double;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (unsigned ll)rng() % B;
}
template<typename t>
istream& operator >> (istream& in, vector<t>& vec) {
    for (t& x : vec)in >> x;
    return in;
}

template<typename t>
ostream& operator << (ostream& out, vector<t>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        out << vec[i];
        if (i < n - 1)out << " ";
    }
    return out;
}

// t should support min-function (operator <)
template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

// t should support max-function (operator <)
template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 3e4+3;

void testCase() {
    int n;
    cin >> n;

    vector<vll> ys(2001, vll());

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        x += 1000;
        y += 1000;
        ys[x].push_back(y);
    }

    for (ll i = 0; i <= 2000; ++i)sort(all(ys[i]));

    ll ans = 0;
    for (ll i = 0; i <= 2000; ++i) if (ys[i].size()) {
        for (ll j = 0; j <= 2000; ++j) if (ys[j].size()) {
            ans = max(ans, (ys[j].back() - ys[i][0])*(ys[j].back() - ys[i][0]) + (i - j) * (i - j));
        }
    }

    ld tot = ans;
    tot = sqrt(tot);
    cout.precision(8);
    cout << fixed << tot << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 1;
    ////cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
