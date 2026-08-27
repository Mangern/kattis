#include <iostream>
#include <vector>
#include <array>

using namespace std;
using ii = array<int, 3>;

int k, n, m;

vector<vector<ii>> adj[8];

int main() {
    cin >> k >> n >> m;

    for (int i = 0; i < n; ++i)adj[i].resize(k);

    for (int i = 0; i < m; ++i) {
        int u, v, d, z;
        cin >> u >> v >> d >> z;
        --u, --v, --d;
        adj[d][u].push_back({v, z, i});
    }

    vector<vector<int>> arrive(n, vector<int>(k, 0));

    vector<int> at(k, 0);

    for (int i = 0; i < k * n; ++i) {
        int a, b, c;
        cin >> a >> b >> c;
        --a, --b;
        arrive[b][a] += c;
    }
    vector<bool> good(m, 0);

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j) {
            at[j] += arrive[i][j];
        }

        vector<int> nxtat(k, 0);
        for (int u = 0; u < k; ++u) {
            for (auto [v, z, fl] : adj[i][u]) {
                if (at[u] >= z) {
                    at[u] -= z;
                    good[fl] = 1;
                    nxtat[v] += z;
                }
            }
        }

        for (int j = 0; j < k; ++j) {
            at[j] += nxtat[j];
        }
    }

    for (int i = 0; i < m; ++i) if (!good[i]) {
        cout << "suboptimal" << endl;
        return 0;
    }

    cout << "optimal" << endl;

}
