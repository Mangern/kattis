// When in doubt, add another state to your dp!
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
const int mxN = (1<<16);
ll n;
ll dp[mxN];
ll a[15];

ll solve(ll mask) {
    if (dp[mask] != -1)return dp[mask];
    if (mask == 0)return 0;

    if (mask & (1LL<<n)) {
        ll ans = INFLL;
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < i; ++j) if ((mask&(1LL<<i))&&(mask&(1LL<<j))) {
                ll nmask = (mask ^ (1LL<<n) ^ (1LL<<i) ^ (1LL<<j));
                ll res = solve(nmask);
                res += a[i];
                ans = min(ans,res);
            }
        }
        dp[mask] = ans;
        return ans;
    }
    // mask[n] == 0

    ll ans = INFLL;

    for (ll i = 0; i < n; ++i) if (!(mask & (1LL<<i))) {
        ll nmask = (mask ^ (1LL<<n) ^ (1LL<<i));
        ll res = solve(nmask);
        res += a[i];
        ans = min(ans,res);
    }

    dp[mask] = ans;
    return ans;
}

void testCase() {
    memset(dp,-1,sizeof dp);
    cin >> n;

    for (int i = 0; i < n; ++i)cin >> a[i];
    sort(a,a+n);

    cout << solve((1<<(n+1))-1) << endl;
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
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
