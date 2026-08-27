#include <bits/stdc++.h>
#include <functional>
#include <limits>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

const int mxN = 2506;

int n;
ii loc[mxN];
ll dist[mxN];
int p[mxN];

vector<ii> adj[mxN];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> loc[i][0] >> loc[i][1];
    }

    cin >> loc[n][0] >> loc[n][1];
    ++n;
    cin >> loc[n][0] >> loc[n][1];
    ++n;

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) if (i != j) {
        ll d = (loc[i][0] - loc[j][0]) * (loc[i][0] - loc[j][0]) + (loc[i][1] - loc[j][1]) * (loc[i][1] - loc[j][1]);
        adj[i].push_back({j, d});
    }

    for (int i = 0; i < n; ++i) {
        dist[i] = numeric_limits<ll>::max();
    }

    int s = n - 2;
    int t = n - 1;

    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;

    pq.push({dist[s], s});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dist[u] < d) continue;

        for (auto [v, w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                p[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    int ptr = p[t];
    vector<int> path;
    while (ptr != s) {
        path.push_back(ptr);
        ptr = p[ptr];
    }

    if (path.empty()) {
        cout << "-" << endl;
    } else {
        while (path.size()) {
            cout << path.back() << endl;
            path.pop_back();
        }
    }

    return 0;
}
