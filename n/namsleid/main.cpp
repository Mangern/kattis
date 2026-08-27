#include <bits/stdc++.h>
using namespace std;

const int mxN = 2e5+5;

int n, m;
vector<int> adj[mxN];
int in[mxN];
vector<vector<int>> ans;

int main() {
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int v;
            cin >> v, --v;
            adj[v].push_back(i);
            ++in[i];
        }
    }

    vector<int> front;

    for (int u = 0; u < n; ++u) {
        if (!in[u])front.push_back(u);
    }
    int rem = n;

    while (rem) {
        ans.push_back(front);
        rem -= front.size();
        vector<int> nfront;
        if (front.empty()) {
            cout << "Omogulegt!" << endl;
            return 0;
        }

        for (int u : front) {
            for (int v : adj[u]) {
                if (!--in[v]) {
                    nfront.push_back(v);
                }
            }
        }
        swap(front,nfront);
    }

    cout << "Mogulegt!" << endl;

    cout << ans.size() << endl;
    for (auto &v : ans) {
        cout << v.size();
        for (auto u : v) cout << " " << u+1;
        cout << endl;
    }
}
