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

void testCase() {
    int h, w;
    cin >> h >> w;
    vector<string> grid(h);
    cin >> grid;

    int n = (2* h + 1) * (2*w+1);

    vector<vector<pair<int,ld>>> adj(n, vector<pair<int,ld>>());

    const ld line = 5.0;
    const ld circ = 3.14159265358979323846 * 2.5;

    auto cti = [&] (int i, int j) {
        return i * (2 * w + 1) + j;
    };

    for (int i = 0; i <= h; ++i) {
        for (int j = 0; j <= w; ++j) {
            int icorn = 2 * i;
            int jcorn = 2 * j;
            int u,v;
            if (i > 0) {

                u = cti(icorn-1, jcorn);
                v = cti(icorn, jcorn);
                adj[u].push_back({v, line});

                v = u;
                u = cti(icorn - 2, jcorn);
                adj[u].push_back({v, line});

            }
            if (j > 0) {
                u = cti(icorn, jcorn - 1);
                v = cti(icorn, jcorn);
                adj[u].push_back({v, line});

                v = u;
                u = cti(icorn, jcorn - 2);
                adj[u].push_back({v, line});

            }

            if (i > 0 && j > 0) {
                if (grid[i-1][j-1] == 'O') {
                    u = cti(icorn - 2, jcorn - 1);
                    v = cti(icorn - 1, jcorn);
                    adj[u].push_back({v,circ});

                    u = cti(icorn - 1, jcorn - 2);
                    v = cti(icorn, jcorn - 1);
                    adj[u].push_back({v,circ});
                }
            }
        }
    }

    priority_queue<pair<int,ld>,vector<pair<int,ld>>,greater<pair<int,ld>>> pq;
    pq.push({0.0, 0});
    vector<ld> dist(n, numeric_limits<ld>::infinity());
    dist[0] = 0.0;

    while (!pq.empty()) {
        auto [d,u] = pq.top();

        pq.pop();

        if (dist[u] < d)continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v],v});
            }
        }
    }

    cout.precision(12);
    cout << fixed << dist[n-1] << endl;
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
