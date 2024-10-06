#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
template<typename t, size_t N>
using ar = array<t, N>;
using ii = ar<ll, 2>;
using vii = vector<ii>;
using vll = vector<ll>;

template<typename t>
istream& operator>>(istream& in, vector<t>& vec) {
    for (t& x : vec) {
        in >> x;
    }
    return in;
}

template<typename t>
ostream& operator<<(ostream& os, vector<t>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << " ";
    }
    return os;
}
#define all(v) begin(v), end(v)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (uint64_t)rng() % B;
}

template<typename t>
t min(const vector<t>& v) {
    return *min_element(all(v));
}

template<typename t>
t max(const vector<t>& v) {
    return *max_element(all(v));
}
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();
const int mxN = 205+6;
const ll MOD  = 1e9+7;

struct point {
    double x;
    double y;
};
const double EPS = 1e-6;

point robots[mxN];
point holes[mxN];

vi adj[2*mxN];
int match[2 * mxN];
bool vis[2 * mxN];

int aug(int u) {
    if (vis[u]) return 0;
    vis[u] = 1;
    for (int& v : adj[u])
        if (match[v] == -1 || aug(match[v])) {
            match[v] = u;
            return 1;
        }
    return 0;
}

void testCase(int m) {
    for (int i = 0; i < m; ++i) {
        cin >> robots[i].x >> robots[i].y;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> holes[i].x >> holes[i].y;
    }

    for (double thresh : {5.0, 10.0, 20.0}) {
        for (int i = 0; i < m; ++i) {
            adj[i].clear();
            for (int j = 0; j < n; ++j) {
                if (hypot(robots[i].x - holes[j].x, robots[i].y - holes[j].y) <= (thresh+EPS) * 10.0) {
                    adj[i].push_back(m+j);
                }
            }
        }
        memset(match, -1, sizeof match);
        int mcbm = 0;
        for (int i = 0; i < m; ++i) {
            memset(vis, 0, sizeof vis);
            mcbm += aug(i);
        }
        cout << "In " << int(thresh) << " seconds " << mcbm << " robot(s) can escape" << endl;
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
    int t = 11;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        int m;
        cin >> m;
        if (!m)break;
        if (tc > 1)cout << endl;
        cout << "Scenario " << tc << endl;
        testCase(m);
    }
    return 0;
}
