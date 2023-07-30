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

    n <<= 1;
    vector<string> name(n);
    
    for (int i = 0; i < n; i += 2) {
        string a, b;
        cin >> a >> b;
        name[i] = a;
        name[i+1] = b;

        // partner(x) == x ^ 1
    }

    string qs;
    cin >> qs;

    vi fr(n, -1);
    vi be(n, -1);

    for (int i = 0; i < n; ++i) {
        if (i > 0)fr[i] = i - 1;
        if (i < n-1)be[i] = i + 1;
    }

    int fst = 0;
    int lst = n - 1;
    int mic = 0;

    for (char c : qs) {
        if (c == 'F') {
            mic = fr[mic];
        } else if (c == 'B') {
            mic = be[mic];
        } else if (c == 'R') {
            int p_be = be[mic];
            if (p_be == -1) {
                mic = fst;
            } else {
                int i = mic;
                mic = p_be;
                fr[p_be] = fr[i];
                if (fr[i] == -1) {
                    fst = p_be;
                } else {
                    be[fr[i]] = p_be;
                }
                be[lst] = i;
                fr[i] = lst;
                lst = i;
                be[i] = -1;
            }
        } else if (c == 'C') {
            int i = mic;
            int j = i^1;

            // extract i and move mic
            if (be[i] == -1) {
                mic = fst;
                lst = fr[i];
            } else {
                mic = be[i];

                fr[be[i]] = fr[i];
            }

            if (fr[i] != -1) {
                be[fr[i]] = be[i];
            } else {
                fst = be[i];
            }

            // insert i behind j

            int p_be = be[j];

            be[j] = i;
            fr[i] = j;

            be[i] = p_be;

            if (p_be != -1) {
                fr[p_be] = i;
            }

            if (j == lst)lst = i;
        } else if (c == 'P') {
            cout << name[mic^1] << endl;
        } else {
            assert(false);
        }
    }

    cout << endl;
    int i = fst;
    while (i != -1) {
        cout << name[i] << endl;
        i = be[i];
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
