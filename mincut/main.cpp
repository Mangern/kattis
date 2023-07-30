// MAX-FLOW MIN-CUT THEOREM:
// "The maximum flow from s to t of a directed graph is equal to the minimum capacity of a cut S,T of the graph.
// Where a cut S,T is a partition of the verticies in the graph such that s \in S ans t \in T
// and the capacity of a cut is the sum of weights of edges (u,v) such that u \in S and v \in T
// i. e. the min cut is the minimum sum of weights of edges you have to cut to make t not reachable from s
//
// Intuitively a maximum flow is limited by a "bottleneck" and this bottleneck is the min cut
//
// This task: find and output the set S in any minimum cut.
//
// Solution: find the maximum flow using ford-fulkerson:
//  While t is reachable from s using non-zero edges:
//   find any path from s to t using non-zero edges
//   find the minimum weight, w along one such path
//   add w to the answer (max-flow)
//   subtract w from the weight of every edge (u,v) along this path
//   add w to the reverse of this edge (v,u) along this path 
//       intuitively this has the effect of
//       1) "breaking" the path, i.e. sending as much flow through this path as possible, so subtracting the bottleneck
//           means we cannot send any more flow through this exact path
//       2) Making our changes reversible, i.e. if we later want flow to go in some other edge, we can relieve our edges of the flow
//           applied at this step by sending flow through the reverse of these edges (and then again, *adding* the flow back to the original edge)
//   A proof of the correctness of this exists
//
// The result of the algorithm is a modified graph where the maximum flow is being "applied":
//  weights represent how much additional flow we could send (or relieve) from one node to another
// However, because the applied flow is maximum, t is no longer reachable from s in this modified graph.
// Conversely, for any node u reachable from s in the modified graph, it holds that t is not reachable from u
// So if we select our answer set S as "all nodes reachable from s in the modified graph", all edges going from S to !S will have
// weight 0 (their sum being the max. flow). And from the max-flow min-cut theorem, this set is an optimal answer.
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;

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
const int mxN = 502;

int n, m;
int s, t;
ll adj[mxN][mxN];
bool vis[mxN];
int par[mxN];

bool flow_bfs() {
    memset(vis, 0, sizeof vis);

    queue<int> q;
    q.push(s);
    vis[s] = 1;

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v) if (adj[u][v] && !vis[v]) {
            vis[v] = 1;
            par[v] = u;
            q.push(v);
        }
    }
    return vis[t];
}

void max_flow() {
    while (flow_bfs()) {
        ll curr = INFLL;

        for (int v = t; v != s; v = par[v]) {
            curr = min(curr, adj[par[v]][v]);
        }

        for (int v = t; v != s; v = par[v]) {
            adj[par[v]][v] -= curr;
            adj[v][par[v]] += curr;
        }
    }
}

bool test_bfs(int u) {
    memset(vis, 0, sizeof vis);
    vis[u] = 1;
    queue<int> q;
    q.push(u);
    while (q.size()) {
        u = q.front();
        q.pop();

        for (int v = 0; v < n; ++v)if (adj[u][v] && !vis[v]) {
            vis[v] = 1;
            q.push(v);
        }
    }
    return vis[s];
}

void testCase() {
    cin >> n >> m >> s >> t;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ll w;
        cin >> w;

        adj[u][v] += w;
    }
    max_flow();

    vi ans;
    flow_bfs();
    for (int u = 0; u < n; ++u)if (vis[u])ans.push_back(u);
    cout << ans.size() << endl;
    for (auto x : ans)cout << x << endl;
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
