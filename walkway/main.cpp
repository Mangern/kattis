#include <bits/stdc++.h>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const int mxN = 5000;

ll n;
ll a[mxN], b[mxN], h[mxN];
// top: a, bot: b
ll cost[mxN];
vector<int> adj[mxN];
ll dist[mxN];

void test() {
    scanf("%lld", &n);
    if (!n) exit(0);

    for (int i = 0; i < n; ++i) {
        scanf("%lld%lld%lld", &a[i], &b[i], &h[i]);

        cost[2*i] = (a[i] + b[i]) * h[i];
        cost[2*i+1] = cost[2*i];
    }

    for (int i = 0; i < 2 * n + 2; ++i) {
        adj[i].clear();
    }

    ll ws, we;
    scanf("%lld%lld", &ws, &we);

    if (ws == we) {
        adj[2*n].push_back(2*n+1);
    }

    for (int i = 0; i < n; ++i) {
        if (ws == b[i]) {
            adj[2*n].push_back(2*i);
        }
        if (ws == a[i]) {
            adj[2*n].push_back(2*i+1);
        }
        if (we == a[i]) {
            adj[2*i].push_back(2*n+1);
        }
        if (we == b[i]) {
            adj[2*i+1].push_back(2*n+1);
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) if (i != j) {
            if (a[i] == b[j]) {
                adj[2*i].push_back(2*j);
            }
            if (a[i] == a[j]) {
                adj[2*i].push_back(2*j+1);
            }
            if (b[i] == b[j]) {
                adj[2*i+1].push_back(2*j);
            }
            if (b[i] == a[j]) {
                adj[2*i+1].push_back(2*j + 1);
            }
        }
    }

    for (int i = 0; i <= 2 * n+1; ++i) {
        dist[i] = numeric_limits<ll>::max();
    }
    dist[2*n] = 0;
    cost[2 * n] = 0;
    cost[2 * n + 1] = 0;
    priority_queue<ii, vector<ii>,greater<ii>> pq;
    pq.push({0, 2 * n});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (int v : adj[u]) {
            if (d + cost[v] < dist[v]) {
                dist[v] = d + cost[v];
                pq.push({dist[v], v});
            }
        }
    }

    printf("%lld.%02lld\n", dist[2*n+1]/100, dist[2*n+1]%100);
}

int main() {
    for (;;)test();
}
