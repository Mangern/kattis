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

void testCase() {
    int n, q;
    cin >> n >> q;

    vi a(n);
    cin >> a;

    if (q == 1) {
        set<int> s;
        for (int i = 0; i < n; ++i) {
            if (s.count(7777-a[i])) {
                cout << "Yes" << endl;
                return;
            }
            s.insert(a[i]);
        }
        cout << "No" << endl;
    } else if (q == 2) {
        set<int> s;
        for (auto x : a) {
            s.insert(x);
        }
        if (s.size() == n) {
            cout << "Unique" << endl;
        } else {
            cout << "Contains duplicate" << endl;
        }
    } else if (q == 3) {
        map<int,int> f;
        for (auto x : a) {
            if (++f[x] >= (n/2)+1) {
                cout << x << endl;
                return;
            }
        }
        cout << -1 << endl;
    } else if (q == 4) {
        sort(all(a));
        if (n & 1) {
            cout << a[n>>1] << endl;
        } else {
            cout << a[(n>>1)-1] << " " << a[n>>1] << endl;
        }
    } else if (q == 5) {
        sort(all(a));

        for (int i = 0; i < n; ++i) {
            if (a[i] >= 100 && a[i] <= 999) {
                cout << a[i] << " ";
            }
        }
        cout << endl;
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
