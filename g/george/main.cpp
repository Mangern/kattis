#include <bits/stdc++.h>
#include <queue>
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

    vector<vll> adj(n+1);
    vector<vll> edge(m+1);

    int a, b, k, g;
    cin >> a >> b >> k >> g;

    vll g_path(g);
    vll close(m+1, -1);
    vll open(m+1, -1);
    cin >> g_path;

    for (int i = 1; i <= m; ++i) {
        ll u, v, w;
        cin >> u >> v >> w;

        edge[i] = vll{u, v, w};
        adj[u].push_back(i);
        adj[v].push_back(i);
    }

    edge[0] = {0, a, k};
    adj[0].push_back(0);

    ll sm = 0;

    for (int i = 1; i < g; ++i) {
        ll u = g_path[i-1];
        ll v = g_path[i];

        for (auto e : adj[u]) {
            if (min(edge[e][0], edge[e][1]) == min(u,v) && max(edge[e][0], edge[e][1]) == max(u,v)) {
                close[e] = sm;
                open[e] = sm + edge[e][2];
                sm += edge[e][2];
                break;
            }
        }
    }

    priority_queue<ii, vii, greater<ii>> pq;

    pq.push({0, 0});
    vll dist(2*n+2, INFLL);
    dist[0] = 0;

    while (pq.size()) {
        ll d = pq.top()[0];
        ll u = pq.top()[1];
        pq.pop();

        if (dist[u] < d)continue;

        ll curr_time = dist[u];

        if (u > n)u -= (n+1);
        for (auto e : adj[u]) {
            if (close[e] != -1 && close[e] <= curr_time && open[e] > curr_time) {
                ll v = u + n+1;

                if (dist[v] > open[e]) {
                    dist[v] = open[e];
                    pq.push({dist[v], v});
                }
            } else {
                ll v = edge[e][0] ^ u ^ edge[e][1];
                if (dist[v] > curr_time + edge[e][2]) {
                    dist[v] = curr_time + edge[e][2];
                    pq.push({dist[v], v});
                }
            }
        }
    }

    cout << dist[b] - k << endl;
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
