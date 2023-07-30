// Bellman-Ford implementation
// without reporting negative cycles, just treat
// paths through them as arbitrarily short.
// Negative weights can be tricky!
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
const ll INFLL = 1e15;

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
    ll n, m, q, s;
    cin >> n >> m >> q >> s;

    if (!n)return false;

    vll dist(n, INFLL);
    dist[s] = 0;

    vector<ar<ll,3>> edge(m);
    for (int i = 0; i < m; ++i) {
        cin >> edge[i][0] >> edge[i][1] >> edge[i][2];
    }

    for (int k = 0; k < n-1; ++k) {
        for (auto [u,v,w] : edge) {
            if (dist[u] == INFLL)continue;
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    vi setneg;
    for (auto [u,v,w] : edge) {
        if (dist[u] == INFLL)continue;
        if (dist[v] > dist[u] + w) {
            setneg.push_back(v);
        }
    }
    for (auto i : setneg) {
        dist[i] = -INFLL;
    }

    for (int k = 0; k < n; ++k) {
        for (auto [u,v,w] : edge) {
            if (dist[u] == -INFLL) {
                dist[v] = -INFLL;
            }
        }
    }


    while (q-->0) {
        int t;
        cin >> t;

        if (dist[t] == -INFLL)cout << "-Infinity" << endl;
        else if (dist[t] == INFLL) cout << "Impossible" << endl;
        else cout << dist[t] << endl;
    }

    return true;
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
