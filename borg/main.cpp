#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

#define all(v) begin(v), end(v)

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};

int main() {
    string line;
    getline(cin, line);
    int T = stoi(line);
    while (T-->0) {
        int n, m;
        getline(cin, line);
        stringstream ss{line};
        ss >> m >> n;
        vector<string> grid(n);
        for (auto &s : grid) {
            getline(cin, s);
        }

        const int INF = n * m * 2;

        vector<int> interesting;
        vector<vector<int>> adj(n * m);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '#') continue;
                if (i > 0 && grid[i-1][j] != '#') {
                    adj[(i - 1) * m + j].push_back(i * m + j);
                    adj[i * m + j].push_back((i - 1) * m + j);
                }
                if (j > 0 && grid[i][j-1] != '#') {
                    adj[i * m + j - 1].push_back(i * m + j);
                    adj[i * m + j].push_back(i * m + j - 1);
                }
                if (grid[i][j] != ' ')interesting.push_back(i * m + j);
            }
        }

        vector<vector<int>> dist(interesting.size(), vi(interesting.size(), 0));

        for (int i = 0; i < interesting.size(); ++i) {
            int start = interesting[i];
            vi bfs_dist(n * m, INF);
            bfs_dist[start] = 0;
            queue<int> q;
            q.push(start);
            while (q.size()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (bfs_dist[u] + 1 < bfs_dist[v]) {
                        bfs_dist[v] = bfs_dist[u] + 1;
                        q.push(v);
                    }
                }
            }
            for (int j = 0; j < interesting.size(); ++j) {
                dist[i][j] = bfs_dist[interesting[j]];
            }
        }

        vector<array<int, 3>> edges;
        for (int i = 0; i < interesting.size(); ++i) {
            for (int j = i + 1; j < interesting.size(); ++j) {
                edges.push_back({dist[i][j], interesting[i], interesting[j]});
            }
        }
        UnionFind uf(n * m);
        sort(all(edges));

        int span = 0;
        for (auto [w, u, v] : edges) {
            if (uf.join(u, v)) {
                span += w;
            }
        }
        cout << span << endl;
    }
}
