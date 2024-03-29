#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<int,2>;

const int mxN = 101;
const ll INF = 1e6;

const ll MOD = 1e9+7;
int n, m, q;
ll dist[mxN][mxN];
vector<ii> in[mxN];
vector<ii> out[mxN];
bool vis[mxN][mxN];

queue<ii> qe;

void upd(int u, int v, ll w) {
    if (dist[u][v] <= w)return;

    dist[u][v] = w;
    qe.push({u,v});
    vis[u][v] = 1;
}

int main() {
    int T;
    cin >> T;

    while (T-->0) {
        cin >> n >> m >> q;

        for (int i = 0; i < n; ++i) {
            in[i].clear();
            out[i].clear();
            for (int j = 0; j < n; ++j) {
                dist[i][j] = INF;
                vis[i][j] = 0;
            }
        }

        for (int i = 0; i < m; ++i) {
            int u, v, z;
            cin >> u >> v >> z, --u, --v;

            out[u].push_back({v, z});
            in[v].push_back({u, z});
        }

        for (int i = 0; i < n; ++i) {
            for (auto [v, z1] : out[i]) {
                for (auto [u, z2] : in[i]) if (z2 > 0 && z2 == -z1) {
                    upd(u, v, 2);
                    //cout << z2 << "-" << u << " " << z1 << "-" << v << endl;
                }
            }
        }

        while (qe.size()) {
            auto [u, v] = qe.front();
            qe.pop();

            if (!vis[u][v])continue;

            vis[u][v] = 0;

            for (auto [b, z1] : out[v]) {
                for(auto [a, z2] : in[u]) if (z2 > 0 && z2 == -z1) {
                    upd(a, b, 2 + dist[u][v]);
                }
            }

            for (int i = 0; i < n; ++i) {
                if (dist[i][u] != INF) {
                    upd(i, v, dist[i][u] + dist[u][v]);
                }

                if(dist[v][i] != INF) {
                    upd(u, i, dist[u][v] + dist[v][i]);
                }
            }
        }


        while (q-->0) {
            int u, v;
            cin >> u >> v, --u, --v;

            ll d = dist[u][v];
            if (d == INF) {
                cout << "impossible" << endl;
            } else {
                cout << d << endl;
            }
        }
    }
    return 0;
}
