#include <bits/stdc++.h>
using namespace std;

int main() {
    multiset<pair<int,int>> edges;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        edges.insert({u,v});
    }

    int w;
    cin >> w;

    int u;
    cin >> u, --u;

    int fail=-1;
    for (int i = 0; i < w; ++i) {
        int v;
        cin >> v, --v;
        if (fail!=-1)continue;

        pair<int,int> edge = {u,v};

        if (!edges.count(edge)) {
            fail=i+1;
            continue;
        }
        edges.erase(edges.find(edge));
        u = v;
    }

    if (fail != -1) {
        cout << fail << endl;
    } else if (edges.size()) {
        cout << "too short" << endl;
    } else {
        cout << "correct" << endl;
    }
}
