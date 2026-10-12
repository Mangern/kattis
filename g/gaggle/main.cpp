#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> p, rnk;

    UnionFind(int n) {
        p.assign(n, 0);
        rnk.assign(n, 0);
        iota(begin(p), end(p), 0);
    }

    int find(int i) {
        return p[i] == i ? i : p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i) == find(j);
    }

    void join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j) return;

        if (rnk[i] > rnk[j]) {
            p[j] = i;
        } else {
            p[i] = j;
            ++rnk[j];
        }
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];

        pq.push(i);
    }

    UnionFind uf(n + 1);

    vector<int> out(n+1, 0), in(n+1, 0);

    for (int u = 1; u < n; ++u) {
        int v = a[u];
        if (!in[v] && !uf.check(u, v)) {
            // Can keep
            in[v] = u;
            out[u] = v;
            uf.join(u, v);
            continue;
        }
        // Find lowest
        while (in[pq.top()]) pq.pop();

        v = pq.top();
        if (uf.check(u, v)) {
            int tmp = v;
            pq.pop();
            while (in[pq.top()]) pq.pop();
            v = pq.top();
            pq.push(tmp);
        }
        in[v] = u;
        out[u] = v;
        uf.join(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (!in[i]) {
            out[n] = i;
            break;
        }
    }

    for (int i = 1; i <= n; ++i)cout << out[i] << ' ';
    cout << endl;
}
