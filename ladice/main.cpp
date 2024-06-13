#include <iostream>
#include <iterator>
#include <vector>
#include <array>
#include <numeric>

using namespace std;

using vi = vector<int>;
#define all(v) begin(v), end(v)

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
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
    int n, l;
    cin >> n >> l;

    UnionFind uf(l);

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;

        uf.join(a, b);

        if (uf.sz[uf.find(a)]) {
            cout << "LADICA" << endl;
            --uf.sz[uf.find(a)];
        } else {
            cout << "SMECE" << endl;
        }

    }
}
