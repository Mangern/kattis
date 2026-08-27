/*
 *  Remember that sometimes it is necessary to use adjacency lists rather than matrices because speed.
 *  Optionally use both?
 * */
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vi = vector<int>;
template<typename T, size_t N>
using ar = array<T,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;

struct edge {
    ll u,v,flow,cost,rev;
};

const int mxN = 253;
const int mxM = 5003;
const ll INF = 1LL<<31;
int n, m;
int s, t;

vector<int> adj[mxN];
vector<edge> edges;

ll dist[mxN];
int par[mxN];
int pari[mxN];
int vis[mxN];
const ll mxFl = (1LL<<31);

bool find_path() {
    for (ll i = 0; i < n; ++i) {
        dist[i] = INF;
        vis[i] = 0;
    }
    deque<int> q;
    q.push_back(s);
    dist[s] = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop_front();
        vis[u] = 2;

        for (auto ei : adj[u]) {
            edge e = edges[ei];
            int v = e.v;
            if (e.flow == 0 || dist[u] + e.cost >= dist[v])continue;
            dist[v] = dist[u] + e.cost;

            if (!vis[v]) {
                q.push_back(v);
            } else if (vis[v] == 2) {
                q.push_front(v);
            }
            vis[v] = 1;
            par[v] = u;
            pari[v] = ei;
        }
    }

    return dist[t] < INF;
}

ii maxFlow() {
    ll ans = 0;
    ll cans = 0;
    while (find_path() && ans < mxFl) {
        ll curr = mxFl - ans;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            curr = min(curr, edges[pari[v]].flow);
        }
        ans += curr;
        for (int v = t; v != s; v = par[v]) {
            int u = par[v];
            edges[pari[v]].flow -= curr;
            edges[edges[pari[v]].rev].flow += curr;

            cans += curr * edges[pari[v]].cost;
        }
    }
    return {ans,cans};
}

int main() {
    cin >> n >> m;
    cin >> s >> t;
    for (int i = 0; i < m; ++i) {
        int a, b;
        ll c;
        cin >> a >> b >> c;
        ll cst; cin >> cst;
        int ab = edges.size();
        int ba = edges.size() + 1;
        adj[a].push_back(ab);
        edges.push_back({a,b,c,cst,ba});
        adj[b].push_back(ba);
        edges.push_back({b,a,0,-cst, ab});
    }
    ii ret = maxFlow();
    cout << ret[0] << " " << ret[1] << endl;
    return 0;
}

