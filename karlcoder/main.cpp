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

template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 2e5+7;

void setIO() {
    //cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

map<ll,int> dp;

int query(ll i) {

    if (dp.count(i)) {
        return dp[i];
    }

    cout << "buf[" << i << "]" << endl;
    int x;
    cin >> x;
    dp[i] = x;
    return x;
}

void submit(ll l) {
    cout << "strlen(buf) = " << l << endl;
}

int main() {
    setIO();
    pre();

    ll n = 2;

    ll lo = 2;
    ll hi = 3;
    while (true) {
        int x = query(2 * n - 1);
        hi = 2 * n - 1;
        if (!x)break;
        lo = 2 * n;
        n *= 2;
    }


    while (lo < hi) {
        ll mid = (lo+hi)/2;

        int x = query(mid);

        if (!x) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }

    submit(lo);

    return 0;
}

