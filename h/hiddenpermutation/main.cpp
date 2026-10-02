#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using BigInt = __int128;
using vi = vector<int>;

// #define double long double

typedef vector<double> vd;
const double eps = 1e-20;

#define all(v) begin(v), end(v)
#define sz(v) (int)(v).size()
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

int solveLinear(vector<vd>& A, vd& b, vd& x) {
    int n = sz(A), m = sz(x), rank = 0, br, bc;
    if (n) assert(sz(A[0]) == m);
    vi col(m); iota(all(col), 0);

    rep(i,0,n) {
        double v, bv = 0;
        rep(r,i,n) rep(c,i,m)
            if ((v = fabs(A[r][c])) > bv)
                br = r, bc = c, bv = v;
        if (bv <= eps) {
            rep(j,i,n) if (fabs(b[j]) > eps) return -1;
            break;
        }
        swap(A[i], A[br]);
        swap(b[i], b[br]);
        swap(col[i], col[bc]);
        rep(j,0,n) swap(A[j][i], A[j][bc]);
        bv = 1/A[i][i];
        rep(j,i+1,n) {
            double fac = A[j][i] * bv;
            b[j] -= fac * b[i];
            rep(k,i+1,m) A[j][k] -= fac*A[i][k];
        }
        rank++;
    }

    x.assign(m, 0);
    for (int i = rank; i--;) {
        b[i] /= A[i][i];
        x[col[i]] = b[i];
        rep(j,0,i) b[j] -= A[j][i] * b[i];
    }
    return rank; // (multiple solutions if rank < m)
}

void fail() {
    cout << "impossible" << endl;
    exit(0);
}

BigInt to_bigint(const string& s) {
    BigInt result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}

string to_string(BigInt b) {
    string res;
    while (b) {
        res.push_back((char)('0' + b%10));
        b /= 10;
    }
    reverse(begin(res), end(res));
    return res;
}

ll bigint_log(BigInt b) {
    ll lg = 0;
    while (b % 2 == 0) {
        ++lg;
        b /= 2;
    }
    if (b != 1) return -1;
    return lg;
}

int main() {
    ll n, k;
    cin >> n >> k;

    vector<ll> ps(k);
    for (auto &p : ps) cin >> p;

    ll L = 1;

    for (auto p : ps) {
        L = lcm(L, p);
        if (L > ps.back()) {
            fail();
        }
    }
    if (L != ps.back()) {
        fail();
    }
    {
        vector<ll> ds;
        for (ll d = 1; d * d <= L; ++d) if (L % d == 0) {
            ds.push_back(d);
            if (d * d < L) {
                ds.push_back(L / d);
            }
        }
        sort(all(ds));
        if (ps != ds) fail();
    }

    vector<BigInt> cnts(k);
    for (auto &c : cnts) {
        string s;
        cin >> s;

        c = to_bigint(s);
    }

    vector<BigInt> c(k);

    for (int i = 0; i < k; ++i) {
        c[i] = cnts[i];
        for (int j = 0; j < i; ++j) {
            if (ps[i] % ps[j] == 0) {
                c[i] += cnts[j];
            }
        }
    }

    vector<ll> logs(k);
    for (int i = 0; i < k; ++i) {
        logs[i] = bigint_log(c[i]);
        if (logs[i] == -1) fail();
    }

    vector<vector<ll>> All(k, vector<ll>(k, 0));
    vector<vector<double>> A(k, vector<double>(k, 0.0));
    vector<double> B(k,0.0);

    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
            All[i][j] = gcd(ps[i], ps[j]);
            A[i][j] = All[i][j];
        }
        B[i] = logs[i];
    }

    vector<double> sol(k);

    if (solveLinear(A, B, sol) != k) {
        fail();
    }
    vector<ll> soll(k);
    for (int i = 0; i < k; ++i) {
        soll[i] = round(sol[i]);
        if (soll[i] < 0) {
            fail();
        }
    }
    for (int i = 0; i < k; ++i) {
        ll sm = 0;
        for (int j = 0; j < k; ++j) {
            sm += soll[j] * All[i][j];
        }
        if (sm != logs[i]) {
            fail();
        }
    }

    vector<ll> comps;

    ll sc = 0;
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < soll[i]; ++j) {
            comps.push_back(ps[i]);
            sc += ps[i];
        }
    }
    if (sc != n) {
        fail();
    }
    ll start = 1;
    for (auto c : comps) {
        for (int i = 0; i < c - 1; ++i) {
            cout << start + i + 1 << ' ';
        }
        cout << start << ' ';
        start += c;
    }
    cout << endl;
}
