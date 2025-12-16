#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, m;
    cin >> n >> m;

    ll mx = 1;

    while (mx <= max(n,m))mx <<= 1;

    vector<ll> dist(mx+1, -1);

    queue<int> q;
    dist[m] = 0;
    q.push(m);
    while (q.size()) {
        ll u = q.front();
        q.pop();

        {
            ll v = u+1;
            if (v <= mx && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        {
            ll v = u - 1;
            if (v >= 0 && dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }

        if (u % 2 == 0) {
            ll v = u >> 1;
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    cout << dist[n] << endl;
}
