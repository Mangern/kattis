#include <bits/stdc++.h>
using namespace std;

const int mxN = 1005;

int n, m;
int p[mxN];
int w[mxN];
int sz[mxN];
unordered_map<int,int> cnt[mxN];

int find(int i) {
    return p[i] == i ? i : (p[i] = find(p[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i != j) {
        p[j] = i;
        sz[i] += sz[j];
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        sz[i] = 1;
        p[i] = i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        join(u,v);
    }
    for (int i = 0; i < n; ++i) {
        ++cnt[find(i)][w[i]];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i == find(i)) {
            int mxw = 0;
            int mxc = 0;
            for (auto [w, c] : cnt[i]) {
                if (c > mxc) {
                    mxw = w;
                    mxc = c;
                }
            }

            ans += sz[i] - mxc;
        }
    }
    cout << ans << endl;
}
