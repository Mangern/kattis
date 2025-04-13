#include <bits/stdc++.h>
using namespace std;

const int mxN = 20;
int n;
int adj[mxN];

void testCase() {
    cin >> n;

    memset(adj, 0, sizeof adj);

    for (int i = 0; i < n; ++i) {
        int d;
        cin >> d;

        adj[i] |= (1<<i);
        for (int j = 0; j < d; ++j) {
            int v;
            cin >> v, --v;
            adj[i] |= (1<<v);
        }
    }

    int ans = n;
    int goal = (1<<n)-1;
    for (int mask = 0; mask < (1<<n); ++mask) {
        int x = mask;
        int res = 0;
        while (x) {
            int l = (x&(-x));

            res |= adj[31 - __builtin_clz(l)];

            x -= l;
        }
        if (res == goal) {
            ans = min(ans, __builtin_popcount(mask));
        }
    }
    cout << ans << endl;
}

int main () {
    int t;
    cin >> t;
    while (t-->0)testCase();
}
