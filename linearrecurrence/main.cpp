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


struct mat {
    ll n;
    ll m;

    vector<vll> data;

    mat(ll _n, ll _m = -1) {
        n = _n;
        m = _m;

        data = vector<vll>(n, vll(n,0));
    }

    void set(ll i, ll j, ll x) {
        if (m != -1) {
            x %= m;
        }
        data[i][j] = x;
    }

    void add(ll i, ll j, ll x) {
        data[i][j] += x;
        if (m != -1)data[i][j] %= m;
    }

    ll get(ll i, ll j) {
        return data[i][j];
    }
};

mat mul(mat a, mat b) {
    assert(a.n == b.n);
    assert(a.m == b.m);

    mat result(a.n,a.m);

    for (ll i = 0; i < a.n; ++i) {
        for (ll j = 0; j < a.n; ++j) {
            for (ll k = 0; k < a.n; ++k) {
                result.add(i,j,a.get(i,k)*b.get(k,j)%a.m);
            }
        }
    }
    return result;
}

mat matpow(mat a, ll b) {
    if (b == 0) {
        mat res(a.n,a.m);
        for (int i = 0; i <= a.n; ++i) {
            res.set(i,i,1);
        }
        return res;
    }
    if (b == 1)return a;

    mat res = matpow(a,b>>1);
    res = mul(res,res);

    if (b&1)res = mul(res,a);

    return res;
}

void testCase() {
    ll n;
    cin >> n;

    vll a(n+1);
    cin >> a;
    mat base(n+1,-1);

    vll x(n);
    cin >> x;

    base.set(0,0,1);

    for (int i = 0; i <= n; ++i)base.set(1,i,a[i]);

    for (int i = 2; i <= n; ++i) {
        base.set(i,i-1,1);
    }

    int q;
    cin >> q;

    while (q-->0) {
        ll t, m;
        cin >> t >> m;

        if (t <= n - 1) {
            cout << x[t]%m << endl;
            continue;
        }
        t -= n-1;

        mat curr(n+1,m);

        for (int i = 0; i <= n; ++i)for (int j = 0; j <= n; ++j)curr.set(i,j,(base.get(i,j)%m+m)%m);

        curr = matpow(curr,t);

        ll v = curr.get(1,0);
        for (int i = 0; i < n; ++i) {
            v = (v + (curr.get(1,i+1)*(x[n-i-1]%m))%m)%m;
            if (v < 0)v += m;
        }
        cout << v << endl;
    }
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
