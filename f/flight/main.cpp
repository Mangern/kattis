#include <algorithm>
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
const int mxN = 2500+6;
const ll MOD  = 1e9+7;

int n;
vi adj[mxN];
int dist[mxN];
int dist2[mxN];
int p[mxN];
ii illegal_edge;

bool ill(ii edge) {
    return illegal_edge == ii{min(edge[0], edge[1]), max(edge[0], edge[1])} 
        || illegal_edge == ii{max(edge[0], edge[1]), min(edge[0], edge[1])};
}

int dfs(int u, int* d, int cf = -1) {
    int mxv = -1;
    for (int v : adj[u]) if (v != cf && !ill({u,v})) {
        d[v] = d[u] + 1;
        p[v] = u;
        int r = dfs(v, d, u);
        if (mxv == -1 || d[r] > d[mxv])mxv = r;
    }
    if (mxv == -1)mxv = u;
    return mxv;
}

ii diameter(int u) {
    dist[u] = 0;
    int fst = dfs(u, dist);
    dist2[fst] = 0;
    int lst = dfs(fst, dist2);
    if (lst == fst) {
        return {0, lst};
    }
    int goal = (1 + dist2[lst])/2;
    int ptr = lst;
    while (dist2[ptr] > goal) {
        ptr = p[ptr];
    }
    return {dist2[lst], ptr};
}

pair<int, ii> solve(ii edge) {
    memset(dist, -1, sizeof dist);
    memset(dist2, -1, sizeof dist2);
    illegal_edge = edge;

    vii results;
    for (int u = 0; u < n; ++u) if (dist[u] == -1) {
        results.push_back(diameter(u));
    }

    assert(results.size() == 2);
    int ret = max(
        (*max_element(all(results)))[0],
        (results[0][0]+1)/2+(results[1][0]+1)/2+1
    );
    return make_pair(ret, ii{results[0][1], results[1][1]});
}

void testCase() {
    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u,v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ans = INF;
    pair<ii,ii> ans_edges;
    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) if (v > u) {
            auto [ret, add] = solve({u, v});
            if (ret < ans) {
                ans = ret;
                ans_edges.first = {u,v};
                ans_edges.second = add;
            }
        }
    }
    cout << ans << endl;
    cout << ans_edges.first[0]+1 << " " << ans_edges.first[1]+1 << endl;
    cout << ans_edges.second[0]+1 << " " << ans_edges.second[1]+1 << endl;
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
