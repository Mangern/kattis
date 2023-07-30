// silly question
// sometimes the simple solution is the intended one
// and O(n^4) works in this case then n <= 100 (and there are 100 test cases !!??)
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

bool testCase() {
    ll n;
    cin >> n;
    if (!n)return 0;

    vector<ld> x(n), y(n);
    for (int i = 0; i < n; ++i)cin >> x[i] >> y[i];

    auto dist = [&] (int i, int j) {
        return sqrt((ld)(x[i] - x[j]) * (x[i] - x[j]) + (ld)(y[i] - y[j]) * (y[i] - y[j]));
    };

    ll m;
    cin >> m;

    const ld INFD = numeric_limits<ld>::infinity();
    vector<vector<ld>> T(n, vector<ld>(n,INFD));
    for (int i = 0; i < n; ++i)T[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        T[u][v] = dist(u,v);
        T[v][u] = T[u][v];
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (T[i][k] == INFD || T[k][j] == INFD)continue;
                if (T[i][k] + T[k][j] < T[i][j]) {
                    T[i][j] = T[i][k] + T[k][j];
                }
            }
        }
    }
    ld tot = 0;
    for (int i = 0; i < n; ++i)for (int j = i+1; j < n; ++j)tot += T[i][j];

    auto check = [&] (int u, int v) {
        vector<vector<ld>> nT(n, vector<ld>(n,INFD));
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                nT[i][j] = T[i][j];
                nT[j][i] = T[j][i];
            }
        }

        nT[u][v] = dist(u,v);
        nT[v][u] = dist(v,u);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nT[i][j] = min(nT[i][j], nT[i][u]+nT[u][v]+nT[v][j]);
                nT[i][j] = min(nT[i][j], nT[i][v]+nT[u][v]+nT[u][j]);
            }
        }

        ld ntot = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j)ntot += nT[i][j];
        }
        return ntot;
    };

    ld ans = tot;
    int ai = -1, aj = -1;

    ld preci = 0.00001;

    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            ld res = check(i,j);
            if (abs(res-ans) > preci && res < ans) {
                ai = i;
                aj = j;
                ans = res;
            }
        }
    }

    if (abs(ans - tot) <= 0.00001) {
        cout << "no addition reduces ";
        cout.precision(12);
        cout << fixed << ans << endl;
    } else {
        cout << "adding " << ai << " " << aj << " reduces ";
        cout.precision(12);
        cout << fixed << tot;
        cout << " to ";
        cout.precision(12);
        cout << fixed << ans << endl;
    }


    return 1;
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

    while (testCase()){}
    return 0;
}
