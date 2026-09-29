#include <bits/stdc++.h>
using namespace std;

/*
 * Find the smallest y in [1949, 2008] such that:
 * - Let G' be the graph obtained by only keeping edges
 *   with weight < y.
 * - Then there exists a clique in G' such that for every edge
 *   e' in G', e' is either a part of the clique or has one endpoint
 *   belonging to the qlique.
 * - The clique has to have size between n/3 and 2n/3
 *
 *   Notice:
 *   - If a vertex u has no neighbors it must be in the RHS
 *   - For some vertex u to be on the RHS, all its neighbors must 
 *     belong to the clique.
 *
 *   - Maintain a clique "current clique".
 *     - Invariant: At every step, "current clique" has to be a clique
 *   - For every vertex u:
 *     - Try to put it in the RHS
 *     - This immediately places its neighbors in LHS
 *     - Continue if LHS is still a clique
 *   - If fails, must be in LHS...
 */

constexpr int mxN = 402;

int n, m;
bitset<mxN> clique;
bitset<mxN> nclique;
bitset<mxN> adj[mxN];

bool search(int u = 0) {
    // Verify cliqueness
    int L = clique.count();
    int R = nclique.count();
    for (int i = 0; i < n; ++i) if (clique.test(i)) {
        if ((adj[i] & clique).count() != L - 1) return false;
    }
    for (int i = 0; i < n; ++i) if (nclique.test(i)) {
        if ((~adj[i] & nclique).count() != R) return false;
    }
    if (u == n) {
        int L = clique.count();
        int R = n - L;
        return max(L, R) * 3 <= 2 * n;
    }

    int deg = adj[u].count();
    bool can_be_clique = 3 * (deg + 1) >= n;
    bool can_be_nclique = 3 * (n - deg) >= n;

    if (clique.test(u)) {
        if (!can_be_clique) return false;
        // No choice
        return search(u + 1);
    }
    if (nclique.test(u)) {
        if (!can_be_nclique) return false;
        return search(u + 1);
    }

    vector<int> to_add_clique;
    vector<int> to_add_nclique;
    if (can_be_nclique) { 
        // try to add to RHS
        bool ok=1;
        for (int v = 0; v < n; ++v) if (v != u) {
            if (adj[u].test(v)) {
                if (nclique.test(v)) {
                    // Illegal
                    ok=0;
                    break;
                }
                if (!clique.test(v))
                    to_add_nclique.push_back(v);
            }
        }

        if (!ok) {
            can_be_nclique = false;
        }
    }

    if (can_be_clique) {
        // must add to clique. non-neighbors go outside clique

        bool ok=1;
        for (int v = 0; v < n; ++v) if (v != u) {
            if (!adj[u].test(v)) {
                if (clique.test(v)) {
                    ok=0;
                    break;
                }
                if (!nclique.test(v)) {
                    to_add_clique.push_back(v);
                }
            }
        }

        if (!ok) can_be_clique = false;
    }

    if (!can_be_clique && !can_be_nclique) return false;
    if (!can_be_clique || to_add_nclique.size() <= to_add_clique.size()) {
        nclique.set(u);
        for (int v : to_add_nclique) {
            clique.set(v);
        }
        if (search(u + 1)) return true;
        for (int v : to_add_nclique) {
            clique.reset(v);
        }
        nclique.reset(u);
        can_be_nclique = false;
    }

    if (can_be_clique) {
        clique.set(u);
        for (int v : to_add_clique) {
            nclique.set(v);
        }
        if (search(u + 1)) return true;
        for (int v : to_add_clique) {
            nclique.reset(v);
        }
        clique.reset(u);
        can_be_clique = false;
    }
    if (can_be_nclique) {
        nclique.set(u);
        for (int v : to_add_nclique) {
            clique.set(v);
        }
        if (search(u + 1)) return true;
        for (int v : to_add_nclique) {
            clique.reset(v);
        }
        nclique.reset(u);
        can_be_nclique = false;
    }

    return false;
}

int main() {
    cin >> n >> m;

    vector<array<int, 3>> edges;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        int w;
        cin >> w;
        edges.push_back({w, u, v});
    }
    sort(edges.begin(), edges.end());

    int eptr = 0;
    for (int y = 1949; y <= 2008; ++y) {
        while (eptr < edges.size()) {
            auto [w, u, v] = edges[eptr];
            if (w >= y) break;
            adj[u].set(v);
            adj[v].set(u);
            ++eptr;
        }

        clique = 0;
        nclique = 0;
        if (search()) {
            cout << y << endl;
            return 0;
        }
    }

    cout << "Impossible" << endl;
}
