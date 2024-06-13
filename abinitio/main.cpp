#include <iostream>

using namespace std;
using ll = long long;

const ll MOD = 1e9+7;

const int mxN = 4005;

int n, m, q;

bool _adj1[mxN*mxN];
bool _adj2[mxN*mxN];

bool trans = 0;
bool inv = 0;

int main() {
    bool* adj = _adj1;
    cin >> n >> m >> q;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;

        adj[u*mxN + v] = 1;
    }

    while (q-->0) {
        int t;
        cin >> t;

        if (t == 1) {
            int u = n;
            ++n;
            for (int i = 0; i < n; ++i) if (i != u) {
                adj[i * mxN + u] = inv;
                adj[u * mxN + i] = inv;
            }
        } else if (t == 2) {
            int u, v;
            cin >> u >> v;

            if (trans) {
                adj[v*mxN + u] = 1 ^ inv;
            } else {
                adj[u*mxN + v] = 1 ^ inv;
            }
        } else if (t == 3) {
            int u;
            cin >> u;

            for (int i = 0; i < n; ++i) {
                adj[u* mxN + i] = 0 ^ inv;
                adj[i* mxN + u] = 0 ^ inv;
            }
        } else if (t == 4) {
            int u, v;
            cin >> u >> v;

            if (trans) {
                adj[v*mxN + u] = 0 ^ inv;
            } else {
                adj[u*mxN + v] = 0 ^ inv;
            }

        } else if (t == 5) {
            trans = !trans;
        } else if (t == 6) {
            inv = !inv;
        }

    }
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        int out = 0;
        for (int j = 0; j < n; ++j) if (i != j) {
            if (trans) {
                out += adj[j * mxN + i] ^ inv;
            } else {
                out += adj[i * mxN + j] ^ inv;
            }
        }
        ll hash = 0;

        cout << out << " ";

        for (int j = n - 1; j >= 0; --j) if (j != i) {
            bool val = trans ? adj[j * mxN + i] : adj[i * mxN + j];
            val ^= inv;
            if (val) {
                hash *= 7;
                hash %= MOD;
                hash += j;
                hash %= MOD;
            }
        }
        cout << hash << endl;
    }
}
