#pragma GCC optimize("Ofast")
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
const int mxN = 1e5+5;

int n, m, k;
vector<ar<ll,2>> adj[mxN];
vector<int> p[mxN];
ll t[mxN];
bool vis[mxN];
stack<int> stk;
int pptr[mxN];
int cf[mxN];
ll dist[mxN];

void dfs(int u) {
    vis[u] = true;
    if (u == 0) {
        stk.push(u);
        return;
    }

    ll pdst = dist[cf[u]];

    for (auto [v,w] : adj[u]) {
        if (dist[v] != pdst)continue;
        if (vis[v])continue;
        dfs(v);
    }
    stk.push(u);
}

void testCase() {
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < n; ++i) {
        scanf("%lld", &t[i]);
    }

    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        --u, --v;
        adj[u].push_back({v, t[v]});
        adj[v].push_back({u, t[u]});
    }

    if (n == 2 && k == 1) {
        printf("impossible\n");
        return;
    }

    dist[0] = 0;
    for (int i = 1; i < n; ++i)dist[i] = INFLL;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (u == n - 1)break;
        if (dist[u] < d)continue;


        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                cf[v] = u;
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            } 
        }
    }

    dfs(n-1);
    string res(n, ' ');
    int nleft = k;
    int sleft = n - k;
    if (cf[n-1] == 0) {
        if (nleft >= 2) {
            res[0] = 'N';
            res[n-1] = 'N';
            nleft -= 2;
        } else {
            res[0] = 'S';
            res[n-1] = 'S';
            sleft -= 2;
        }
    } else {
        while (stk.size() && nleft && sleft) {
            int u = stk.top();
            stk.pop();
            if (nleft) {
                res[u] = 'N';
                --nleft;
            } else {
                res[u] = 'S';
                --sleft;
            }
        }
    }

    for (int i = 0; i < n; ++i) if (res[i] == ' ') {
        if (nleft) {
            res[i] = 'N';
            --nleft;
        } else {
            res[i] = 'S';
            --sleft;
        }
    }

    printf("%s\n", res.c_str());

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
//    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}

