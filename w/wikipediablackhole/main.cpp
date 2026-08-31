#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> art_id;
int idT;

int getid(const string& name) {
    if (art_id.count(name)) return art_id[name];
    return art_id[name] = idT++;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> adj(2*n), radj(2*n);
    string s;
    cin >> s;
    int start = getid(s);

    for (int i = 0; i < n; ++i) {
        string t;
        cin >> s >> t;

        int u = getid(s);
        int v = getid(t);
        adj[u].push_back(v);
        radj[v].push_back(u);
    }
    queue<int> q;
    vector<int> dist(2*n, -1);
    q.push(start);
    dist[start] = 0;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        for (int v : radj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    int ans = 3 * n;
    for (auto nxt : adj[start]) {
        if (dist[nxt] != -1) {
            ans = min(ans, dist[nxt] + 1);
        }
    }

    if (ans == 3 * n) cout << "NO BLACK HOLE" << endl;
    else cout << ans << endl;
}
