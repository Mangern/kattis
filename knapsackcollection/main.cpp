// Kind of "why is n so small"-vibes. For such problems
// write code to be *dumb* on the variables with small constraints
// In this case: O(n^2), and s,t could be as big as 10^7, but 
// only the size of n mattered in this case
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
    ll n, s, t;
    cin >> n >> s >> t;

    multiset<ll> ks;
    set<ll> uniq;
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        ks.insert(k);
        uniq.insert(k);
    }

    auto check = [&] (ll i) {
        multiset<ll> cpy = ks;

        ll wait = 0;

        while (cpy.size()) {
            auto it = cpy.lower_bound(i);
            if (it == cpy.end())it = cpy.lower_bound(0);
            wait += (*it - i+s)%s;
            i = *it;
            cpy.erase(it);
            wait += t;
            i += t;
            i %= s;
        }
        return wait;
    };

    ll sm = 0;
    vll idx;
    vll dp;
    ll mn = INFLL;
    for (auto i : uniq) {
        idx.push_back(i);
        dp.push_back(check(i));
        mn = min(mn, dp.back());
    }

    ll mx = 0;
    for (int i = 0; i < idx.size(); ++i) {
        ll bef;
        if (i == 0) {
            bef = idx[i]+1 + s - 1 - idx.back();
        } else {
            bef = idx[i] - idx[i-1];
        }
        sm += dp[i] * bef;
        sm += ((bef-1)*(bef))/2;
        mx = max(mx, dp[i]+bef-1);
    }
    cout << mn << endl;
    cout << mx << endl;
    ll g = __gcd(sm,s);
    sm /= g;
    s /= g;
    cout << sm << "/" << s << endl;
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
