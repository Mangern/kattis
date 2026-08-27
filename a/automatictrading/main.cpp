#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

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

ll modpow(ll x, ll y, ll m) {
    if (y == 0)return 1;
    ll r = modpow(x, y / 2, m);
    r = (r * r) % m;
    if (y & 1)r = (r * x) % m;
    return r;
}

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool merge(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};

const ll MOD = 1e9+7;

const int mxN = 3e4+3;

const ll A = 911382323;
const ll B = 972663749;


void testCase() {
    string s;
    cin >> s;
    ll n = s.length();

    vll h(n);
    vll p(n);

    h[0] = (s[0] - 'A');
    for (ll i = 1; i < n; ++i)h[i] = ((h[i-1] * A)%B + s[i]-'A') % B;

    p[0] = 1;
    for (ll i = 1; i < n; ++i)p[i] = (p[i-1] * A)%B;

    auto sub_hash = [&] (ll a, ll b) {
        assert(a <= b);
        assert(a >= 0);
        assert(b <  n);
        if (a==0)return h[b];
        return ((h[b] - h[a-1] * p[b-a+1])%B+B)%B;
    };

    auto sub_check = [&] (ll a, ll b, ll x, ll y) {
        for (ll i = 0; a+i <= b; ++i) {
            if (s[a+i] != s[x+i])return false;
        }
        return true;
    }; 

    int q;
    cin >> q;
    while (q-->0) {
        int i, j;
        cin >> i >> j;

        ll lo = 0;
        ll hi = n - j;

        while (lo < hi) {
            ll mid = (lo+hi+1)>>1;

            // is s[i..i+mid-1] == s[j..j+mid-1]?
            if (sub_hash(i,i+mid-1) == sub_hash(j,j+mid-1)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cout << lo << endl;
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
