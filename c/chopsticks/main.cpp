#include <bits/stdc++.h>
using namespace std;

int main() {
    map<pair<int,int>, int> cnt;
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++cnt[{u,v}];
    }

    int have = 0;

    for (auto &[k, v] : cnt) {
        have += v / 2;
    }

    cout << (have >= n ? "yes": "no") << endl;
}
