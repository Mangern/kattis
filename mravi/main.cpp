#include <bits/stdc++.h>
using namespace std;

using ld = long double;
using edge = tuple<int,ld,bool>; 

const int mxN = 1001;

int n;
edge adj[mxN];
ld limit[mxN];


int main() {
    cin >> n;

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        ld x;
        int t;
        cin >> u >> v >> x >> t;
        --u, --v;

        x /= 100.0;

        adj[v] = edge{u, x, t == 1};
    }

    for (int i = 0; i < n; ++i)cin >> limit[i];

    ld ans = 0.0;

    for (int i = 0; i < n; ++i) {
        if (limit[i] == -1)continue;

        int u = i;

        ld curr = limit[i];

        while (u) {
            edge e = adj[u];

            if (get<2>(e))curr = sqrt(curr);
            curr /= get<1>(e);

            u = get<0>(e);
        }
        ans = max(ans, curr);
    }
    cout << ans << endl;

}
