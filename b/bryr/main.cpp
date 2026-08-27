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

template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

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
    int n, m;
    cin >> n >> m;

    vector<vii> adj(n,vii());

    for (int i = 0; i < m; ++i) {
        int u,v,w;
        cin >> u >> v >> w;
        --u,--v;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    vll dist(n,INFLL);
    dist[0] = 0;

    priority_queue<ii,vii,greater<ii>> pq;
    pq.push({0,0});
    while (pq.size()) {
        auto [d,u] = pq.top();
        pq.pop();

        if (dist[u] < d)continue;

        for (auto [v,w] : adj[u]) {
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({dist[v],v});
            }
        }
    }
    cout << dist[n-1] << endl;
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
