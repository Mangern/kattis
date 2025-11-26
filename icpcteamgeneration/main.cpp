#include <bits/stdc++.h>
using namespace std;
using ii = array<int,2>;

const int mxN = 55;

ii pref[mxN];
vector<int> adj[mxN];
bool isa[mxN][mxN];
bool vis[mxN];
int ans;
int n;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        auto &[a,b] = pref[i];
        cin >> a >> b, --a, --b;
    }

    for (int i = 0; i < n; ++i) {
        isa[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            auto [ai, bi] = pref[i];
            auto [aj, bj] = pref[j];

            if (aj <= i && i <= bj && ai <= j && j <= bi) {
                adj[i].push_back(j);
                adj[j].push_back(i);
                isa[i][j] = 1;
                isa[j][i] = 1;
            }
        }
    }

    bool found = true;
    while (found) {
        found = false;
        for (int i = n - 1; i >= 0; --i) if (!vis[i]) {
            for (int j : adj[i]) if (j > i && !vis[j]) {
                for (int k : adj[j]) if (k > j && !vis[k]) {
                    if (isa[k][i]) {
                        vis[i] = vis[j] = vis[k] = 1;
                        ++ans;
                        found = 1;
                    }
                }
            }
        }
    }

    cout << ans << endl;
}
