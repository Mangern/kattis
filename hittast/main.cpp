#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const ll INF = numeric_limits<ll>::max() / 4;

const int mxN = 1e5+5;

ll n, m;
vector<ii> aadj[mxN];
vector<ii> badj[mxN];
ll price[mxN];
ll dista[mxN];
ll distb[mxN];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> price[i];

        dista[i] = INF;
        distb[i] = INF;
    }

    for (int i = 0; i < m; ++i) {
        ll u, v, wa, wb;
        cin >> u >> v >> wa >> wb, --u, --v;
        aadj[u].push_back({v, wa});
        aadj[v].push_back({u, wa});
        badj[u].push_back({v, wb});
        badj[v].push_back({u, wb});
    }

    dista[0] = 0;
    distb[n-1] = 0;

    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, 0});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dista[u] < d) continue;

        for (auto [v, w] : aadj[u]) {
            if (dista[v] > dista[u] + w) {
                dista[v] = dista[u] + w;
                pq.push({dista[v], v});
            }
        }
    }

    pq.push({0, n-1});
    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (distb[u] < d) continue;

        for (auto [v, w] : badj[u]) {
            if (distb[v] > distb[u] + w) {
                distb[v] = distb[u] + w;
                pq.push({distb[v], v});
            }
        }
    }
    ll ans = INF;
    for (int i = 0; i < n; ++i) {
        ans = min(ans, dista[i]+distb[i]+price[i]);
    }
    cout << ans << endl;
}
