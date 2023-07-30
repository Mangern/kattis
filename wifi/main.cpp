// AGAIN: Floating point arithmetic = do random shit until AC (lol)
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
    ll n, m;
    cin >> n >> m;

    vector<ld> a(m);
    cin >> a;

    if (n >= m) {
        cout.precision(1);
        cout << fixed << 0.0 << endl;
        return;
    }

    sort(all(a));

    ld lo = 0.0;
    ld hi = (a.back() - a[0]);

    while (hi - lo >= 0.01) {
        ld mid = (hi+lo)/2;
        //cout << "Checking: " << mid << endl;

        vector<ld> loc;
        loc.push_back(a[0]+mid);

        int i = 1;
        while (loc.size() < n) {
            while (i < m && abs(a[i] - loc.back()) <= mid)++i;
            if (i==m)break;
            loc.push_back(a[i] + mid);
        }
        //cout << "    " << loc << endl;
        //cout << " -> " << abs(loc.back() - a.back()) << endl;
        if (abs(loc.back()-a.back()) <= mid) {
            hi = mid;
        } else lo = mid;
    }
    cout.precision(1);
    cout << fixed << lo << endl;
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
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
