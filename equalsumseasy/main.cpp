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
    ll n;
    cin >> n;

    vll a(n);
    cin >> a;
    map<ll,vll> sms;
    for (ll mask = 0; mask < (1LL<<n); ++mask) {
        ll sm = 0;
        for (int i = 0; i < n; ++i)if (mask & (1<<i)) {
            sm += a[i];
        }
        sms[sm].push_back(mask);
    }

    for (auto pp : sms) {
        if (pp.second.size() >= 2) {
            for (int t = 0; t < 2; ++t) {
                ll mask = pp.second[t];
                for (ll i = 0; i < n; ++i)if (mask & (1LL<<i)) {
                    cout << a[i] << " ";
                }
                cout << endl;
            }
            return;
        }
    }
    cout << "Impossible" << endl;
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
        cout << "Case #" << tc << ": " << endl;
        testCase();
    }
    return 0;
}
