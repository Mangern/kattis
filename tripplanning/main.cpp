#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> edge(n, -1);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;

        if (u == (v + 1) % n) swap(u,v);

        if (v != (u + 1) % n) continue;

        edge[u] = i;
    }

    if (n == 2) {
        edge[0] = max(edge[0], edge[1]);
        edge[1] = max(edge[0], edge[1]);
    }

    if (*min_element(begin(edge),end(edge)) == -1) {
        cout << "impossible" << endl;
        return 0;
    }
    for (auto e : edge)cout << e+1 << endl;
}
