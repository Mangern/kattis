#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(begin(p),end(p),0);
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
    int n, m;
    cin >> n >> m;

    UnionFind uf(n);
    vector<int> in(n, 0), out(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        ++out[u];
        ++in[v];
        uf.join(u, v);
    }

    if (uf.num_sets != 1) {
        cout << "no" << endl;
        return 0;
    }

    vector<int> start, finish;

    for (int i = 0; i < n; ++i) {
        if (in[i] == out[i]) continue;
        else if (in[i] + 1 == out[i]) {
            start.push_back(i);
        } else if (out[i] + 1 == in[i]) {
            finish.push_back(i);
        } else {
            cout << "no" << endl;
            return 0;
        }
    }

    if (start.empty() && finish.empty()) {
        cout << "anywhere" << endl;
        return 0;
    }

    if (start.size() == 1 && finish.size() == 1) {
        cout << start[0]+1 << " " << finish[0] + 1 << endl;
        return 0;
    }

    cout << "no" << endl;
}
