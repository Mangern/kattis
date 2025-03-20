#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

const ll INF = numeric_limits<ll>::max();

const int mxN = 505;
const int mxK = 12;

int n, m, k;

vector<int> grid[mxN];
bool ispass[mxN][mxN];

// Graph size: k * n * m
// node id: level * n * m + row * m + col
ll dist[mxN * mxN * mxK];


int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            int x;
            cin >> x;
            grid[i].push_back(x);
        }
    }

    for (int i = 1; i < n - 1; ++i) {
        for (int j = 1; j < m - 1; ++j) {
            int ver[2] = {
                grid[i-1][j],
                grid[i+1][j]
            };
            int hor[2] = {
                grid[i][j-1],
                grid[i][j+1]
            };
            if (ver[0] == -1 || ver[1] == -1 || hor[0] == -1 || hor[1] == -1) continue;
            if (min(ver[0], ver[1]) > grid[i][j] && max(hor[0], hor[1]) < grid[i][j]) {
                ispass[i][j] = 1;
            }
        }
    }

    int s = (k+1) * n * m;
    int t = s + 1;

    for (int i = 0; i < mxN * mxN * mxK; ++i)dist[i] = INF;
    dist[s] = 0;
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});
    vector<ii> adj;

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();


        if (dist[u] < d) continue;

        if (u == t) {
            cout << d << endl;
            return 0;
        }
        adj.clear();

        if (u == s) {
            for (int i = 0; i < n; ++i) {
                if (grid[i][0] != -1) {
                    if (ispass[i][0]) {
                        int v = n * m + i * m + 0;
                        adj.push_back({v, grid[i][0]});
                    } else {
                        int v = i * m + 0;
                        adj.push_back({v, grid[i][0]});
                    }
                }
            }
        } else {
            int idx = u % (n * m);
            int level = u / (n * m);
            int i = idx / m;
            int j = idx % m;

            if (j == m - 1 && level == k) {
                for (int i = 0; i < n; ++i) {
                    if (grid[i][m-1] != -1) {
                        int v = k * n * m + i * m + m - 1;
                        adj.push_back({t, 0});
                    }
                }
            } else if (j < m - 1) {
                for (auto [ni, nj] : vector<ii>{{i - 1, j + 1}, {i, j + 1}, {i + 1, j + 1}}) {
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
                    if (grid[ni][nj] == -1) continue;

                    if (ispass[ni][nj]) {
                        if (level == k) continue;
                        int v = (level + 1) * n * m + ni * m + nj;
                        adj.push_back({v, grid[ni][nj]});
                    } else {
                        int v = level * n * m + ni * m + nj;
                        adj.push_back({v, grid[ni][nj]});
                    }
                }
            }
        }

        for (auto [v, w] : adj) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[t] == INF) cout << "impossible" << endl;
    else cout << dist[t] << endl;
}
