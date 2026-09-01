#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int eid=0;
    vector<vector<pair<int,int>>> adj(n);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].emplace_back(v,eid);
        adj[v].emplace_back(u,eid);
        ++eid;
    }

    vector<int> order(n, -1);
    queue<int> q;
    q.push(0);
    order[0] = 0;
    int T = 1;
    vector<int> seq(n,0);
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (auto [v, _] : adj[u]) {
            if (order[v] == -1) {
                seq[T] = v;
                order[v] = T++;
                q.push(v);
            }
        }
    }

    int lo = 1;
    int hi = n - 1;

    while (lo < hi) {
        vector<int> qry(m, 0);
        int mid = (lo + hi + 1) / 2;

        // cout << "The range is: " << lo+1 << ", " << hi+1 << ", candidate: " << mid+1 << endl;

        vector<bool> vis(n, 0);
        vis[0] = 1;
        q.push(0);

        while (q.size()) {
            int u = q.front();
            q.pop();
            for (auto [v, eid] : adj[u]) {
                if (!vis[v]) {
                    if (order[v] < mid) {
                        qry[eid] = 1;
                    }
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }

        cout << "?";
        for (int e : qry) cout << ' ' << e;
        cout << endl;

        int ans;
        cin >> ans;
        if (ans) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }

    cout << "! " << seq[lo]+1 << endl;
}
