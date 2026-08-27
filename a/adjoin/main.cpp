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
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;

vi adj[mxN];
int dist[mxN];
int dist2[mxN];

int dfs(int u, int* d, int cf = -1) {
    int mxv = -1;
    for (int v : adj[u]) if (v != cf) {
        d[v] = d[u] + 1;
        int ret = dfs(v, d, u);
        if (mxv == -1 || d[ret] > d[mxv])mxv = ret;
    }
    if (mxv == -1)mxv = u;
    return mxv;
}

int diameter(int u) {
    dist[u] = 0;
    int far = dfs(u, dist);
    dist2[far] = 0;
    return dist2[dfs(far, dist2)];
}


void testCase() {
    int n, m;
    cin >> n >> m;
    memset(dist, -1, sizeof dist);
    memset(dist2, -1, sizeof dist2);

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vi dias;
    for (int u = 0; u < n; ++u) if (dist[u] == -1) {
        dias.push_back(diameter(u));
    }

    if (dias.size() == 1) {
        cout << dias[0] << endl;
        return;
    }
    int mxi = max_element(all(dias)) - begin(dias);
    int ans = dias[mxi];

    vi added;
    for (int i = 0; i < dias.size(); ++i) if (i != mxi) {
        ans = max(ans, (dias[mxi]+1)/2 + 1 + (dias[i]+1)/2);
        added.push_back(1+(dias[i]+1)/2);
    }
    sort(all(added));
    if (added.size() >= 2) {
        ans = max(ans, added.back() + added[added.size()-2]);
    }
    cout << ans << endl;
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
