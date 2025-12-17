#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using edge = array<ll,3>;

const int mxN = 1e5+5;

int n,m;
vector<edge> adj[mxN];

int main() {
    ll A, H;
    cin >> A >> H;
    cin >> n >> m;


    for (int i = 0; i < m; ++i) {
        ll a,h,u,v;
        cin >> u >> v >> a >> h; 
        --u, --v;

        adj[u].push_back({v, a, h});
    }

    vector<ll> maxh(n, 0);
    maxh[0] = H;
    priority_queue<ii> pq;
    pq.push({H, 0});

    while (pq.size()) {
        auto [hp, u] = pq.top();
        pq.pop();

        if (maxh[u] > hp) continue;

        for (auto [v, a, h] : adj[u]) {
            ll needattack = (h + A - 1) / A;

            if (hp - (needattack - 1) * a > 0) {
                ll nhp = hp - (needattack - 1) * a;

                if (maxh[v] < nhp) {
                    maxh[v] = nhp;
                    pq.push({maxh[v], v});
                }
            }
        }
    }

    if (maxh[n-1] == 0) {
        cout << "Oh no" << endl;
    } else cout << maxh[n-1] << endl;
}
