#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5+5;

int p[mxN];
int sz[mxN];

int find(int i) {
    return i == p[i] ? i : (p[i] = find(p[i]));
}

void join(int i, int j) {
    i = find(i);
    j = find(j);
    if (i == j) return;

    p[i] = j;
    sz[j] += sz[i];
}

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n; ++i) {
        int u;
        cin >> u, --u;
        join(u, i);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) if (find(i) == i && sz[i] > 1) {
        ans += sz[i] + 1;
    }
    cout << ans << endl;
}
