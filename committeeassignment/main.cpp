#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, int> id;
vector<vector<int>> adj;
int best_so_far;

int search(int idx, int mx, vector<int>& colors) {
    if (idx == n) return mx;
    if (mx > best_so_far) return mx;

    int dis = 0;
    for (int v : adj[idx]) if (colors[v] != -1) {
        dis |= (1<<colors[v]);
    }

    // try assigning to existing
    for (int i = 0; i < mx; ++i) {
        if ((dis >> i)&1) continue;

        colors[idx] = i;
        best_so_far = min(best_so_far, search(idx + 1, mx, colors));
        colors[idx] = -1;
    }

    colors[idx] = mx;
    best_so_far = min(best_so_far, search(idx+1, mx+1, colors));
    colors[idx] = -1;
    return best_so_far;
}

void testCase() {
    cin >> n >> m;

    if (!n&&!m)exit(0);

    id.clear();

    int idcnt = 0;
    best_so_far = n;
    adj = vector<vector<int>>(n);
    for (int i = 0; i < m; ++i) {
        string s, t;
        cin >> s >> t;

        if (!id.count(s))id[s] = idcnt++;
        if (!id.count(t))id[t] = idcnt++;

        if (id[t]<id[s])
            adj[id[s]].push_back(id[t]);
        if (id[s]<id[t])
        adj[id[t]].push_back(id[s]);
    }

    vector<int> colors(n, -1);
    cout << search(0, 0, colors) << endl;
}

int main() {
    for (;;) {
        testCase();
    }
    return 0;
}
