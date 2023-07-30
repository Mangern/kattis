#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;

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

    vector<vll> T(n, vll(n,0));

    for (ll k = 0; k < (n * (n-1))/2; ++k) {
        ll i, j, t;
        cin >> i >> j >> t;
        T[i][j] = t;
        T[j][i] = t;
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                T[i][j] = min(T[i][j], T[i][k]+T[k][j]);
                T[j][i] = T[i][j];
            }
        }
    }

    vector<map<ll,ll>> lc(n, map<ll,ll>()); // key[start_time] = index in dp

    vector<vll> lec(m, vll(3));
    for (int i = 0; i < m; ++i)cin >> lec[i][2] >> lec[i][0] >> lec[i][1];

    sort(all(lec));
    reverse(all(lec));

    ll ans = 0;

    for (int i = 0; i < m; ++i) {
        ll c = lec[i][2];
        ll s = lec[i][0];
        ll e = lec[i][1];

        ll cur = 1;
        for (int j = 0; j < n; ++j) {
            ll c_time = e + T[c][j];

            auto pp = lc[j].lower_bound(c_time);
            if (pp != lc[j].end()) {
                cur = max(cur, pp->second+1);
            }
            pp = lc[j].lower_bound(s+T[c][j]);
            if (pp != lc[j].end()) {
                cur = max(cur, pp->second);
            }
        }
        ans = max(ans,cur);
        lc[c][s] = max(lc[c][s], cur);
    }
    cout << ans << endl;
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
