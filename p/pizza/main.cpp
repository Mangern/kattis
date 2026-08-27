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
    ll m,n;
    cin >> m >> n;

    vector<vll> g(n,vll(m));
    for (auto& v : g)cin >> v;

    vector<vll> p(n,vll(m));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            p[i][j] = g[i][j];
            if (i > 0)p[i][j] += p[i-1][j];
            if (j > 0)p[i][j] += p[i][j-1];
            if (i > 0 && j > 0)p[i][j] -= p[i-1][j-1];
        }
    }

    auto rect = [&] (int i1, int j1, int i2, int j2) {
        ll sm = p[i2][j2];
        if (i1 > 0)sm -= p[i1-1][j2];
        if (j1 > 0)sm -= p[i2][j1-1];
        if (i1 > 0 && j1 > 0)sm += p[i1-1][j1-1];
        return sm;
    };

    ll tot = 0;

    for (ll i = 0; i < n; ++i) for (ll j = 0; j < m; ++j) {
        tot += g[i][j] * (i+j);
    }
    ll i = 0;
    ll j = 0;
    ll dj = 1;

    ll ans = tot;

    while (i < n) {
        ans = min(ans,tot);

        if (j == 0 && dj == -1) {
            dj = 1;
            ++i;
            tot -= rect(i,0,n-1,m-1);
            tot += rect(0,0,i-1,m-1);
        } else if (j == m - 1 && dj == 1) {
            dj = -1;
            ++i;
            tot -= rect(i,0,n-1,m-1);
            tot += rect(0,0,i-1,m-1);
        } else {
            if (dj == 1) {
                ++j;
                tot -= rect(0,j,n-1,m-1);
                tot += rect(0,0,n-1,j-1);
            } else {
                --j;
                tot -= rect(0,0,n-1,j);
                tot += rect(0,j+1,n-1,m-1);
            }
        }
    }
    cout << ans << " blocks" << endl;
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
