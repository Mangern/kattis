#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

const int mxN = 1e5+5;
const int INF = 1e9;

int n;
vector<ii> adj[mxN];

vector<vector<int>> partitions[4];

void pre() {
    for (int a = 1; a <= 4; ++a) {
        for (int b = 0; b <= 4; ++ b) {
            for (int c = 0; c <= 4; ++c) {
                for (int d = 0; d <= 4; ++d) {
                    int k = a + b + c + d - 1;
                    if (k < 4) {
                        vector<int> part;
                        part.push_back(a);
                        if (b)part.push_back(b);
                        if (c)part.push_back(c);
                        if (d)part.push_back(d);
                        partitions[k].push_back(part);
                    }
                }
            }
        }
    }
    for (int k = 0; k < 4; ++k) {
        sort(begin(partitions[k]), end(partitions[k]));
        partitions[k].erase(unique(begin(partitions[k]), end(partitions[k])), end(partitions[k]));
    }
}

// return: weight heaviest path(s) from 
//     1 leaf  (1 path)
//     2 leafs (1 path)
//     3 leafs (<= 2 paths)
//     4 leafs (<= 2 paths)
array<int, 4> dfs(int u, int cf = -1) {
    array<vector<ii>, 4> child_res;
    for (auto [v, w] : adj[u]) if (v != cf) {
        array<int, 4> sub = dfs(v, u);
        for (int i = 0; i < 4; ++i) {
            int val = sub[i];
            // Can always extend with this edge
            if (i == 0 || i == 2)val += w;
            child_res[i].push_back({val, v});
        }
    }
    for (int i = 0; i < 4; ++i) {
        sort(child_res[i].rbegin(), child_res[i].rend());
    }
    array<int,4> ret={0,0,0,0};
    for (int k = 0; k < 4; ++k) {
        for (const auto& part : partitions[k]) {
            set<int> vis;
            array<int, 4> ptr = {0,0,0,0};
            int here = 0;
            for (auto x : part) {
                while (ptr[x-1] < child_res[x-1].size()) {
                    auto [val, v] = child_res[x-1][ptr[x-1]++];
                    if (!vis.count(v)) {
                        here += val;
                        vis.insert(v);
                        break;
                    }
                }
            }
            ret[k] = max(ret[k], here);
        }
    }
    return ret;
}

int main() {
    pre();
    cin >> n;

    int total_weight = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
        total_weight += w;
    }

    cout << total_weight * 2 - dfs(1)[3] << endl;
}
