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
const int mxN = 1e4+3;


ll spf[mxN];


void testCase() {
    ll M = 1000000000;
    ll n;
    vll chunks(1,1);
    cin >> n;

    auto mul = [&] (ll x) {
        vll a(chunks.size());
        vll b(chunks.size());
        for (ll i = 0; i < chunks.size(); ++i) {
            a[i] = (chunks[i] * x) % M;
            b[i] = (chunks[i] * x) / M;
        }

        for (ll i = 0; i < b.size(); ++i) {
            if (b[i]) {
                if (i == b.size() - 1)a.push_back(0);
                a[i+1] += b[i];
                ll r = a[i+1] / M;
                a[i+1] %= M;
                if (r) {
                    if (i == b.size() - 1)b.push_back(0);
                    b[i+1] += r;
                }
            }
        }
        chunks = a;
    };

    unordered_multiset<ll> ps;
    for (ll i = 2; i <= n+1; ++i) {
        ll x = i;
        while (x > 1) {
            ps.insert(spf[x]);
            x /= spf[x];
        }
    }


    vll a;
    for (ll i = n+1; i <= 2*n; ++i) {
        ll x = i;
        while (x > 1) {
            if (ps.count(spf[x])) {
                ps.erase(ps.find(spf[x]));
            } else {
                a.push_back(spf[x]);
            }
            x /= spf[x];
        }
    }

    for (auto p : a)mul(p);
    while (chunks.size()) {
        cout << chunks.back();
        chunks.pop_back();
    }
    cout << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
    for (ll i = 2; i < mxN; ++i) {
        if (spf[i])continue;
        spf[i] = i;
        for (ll j = i * i; j < mxN; j += i) if (!spf[j]) {
            spf[j] = i;
        }
    }
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
