#include <bits/stdc++.h>
using namespace std;

void testcase() {
    int n, m;
    cin >> n >> m;
    vector<int> early(m, 0);

    vector<int> pot(n);
    vector<vector<int>> cat(n);

    vector<vector<int>> here(m);

    for (int i = 0; i < n; ++i) {
        cin >> pot[i], --pot[i];
        int k;
        cin >> k;

        here[pot[i]].push_back(i);

        for (int j = 0; j < k; ++j) {
            int p;
            cin >> p, --p;
            cat[i].push_back(p);
            early[p] = max(early[p], pot[i]);
        }
    }
    vector<int> ass(m, -1);
    set<int> rem;
    for (int i = 0; i < m; ++i) {
        if (here[i].empty()) {
            rem.insert(i);
            continue;
        }

        set<int> poss;

        for (int p : cat[here[i][0]]) if (ass[p] == -1) {
            if (early[p] <= i) poss.insert(p);
        }

        for (int j = 1; j < here[i].size(); ++j) {
            set<int> nw;
            for (int p : cat[here[i][j]]) if (ass[p] == -1) {
                if (poss.count(p)) {
                    nw.insert(p);
                }
            }
            swap(poss,nw);
        }
        if (poss.empty()) {
            cout << "no" << endl;
            return;
        }

        int p = *poss.begin();
        ass[p] = i;
    }

    vector<int> idx(m);
    iota(begin(idx), end(idx), 0);
    sort(begin(idx), end(idx), [&](auto i, auto j) {
        return early[i] > early[j];
    });

    for (int i : idx) {
        if (ass[i] != -1) continue;
        auto it = rem.lower_bound(early[i]);
        if (it == rem.end()) {
            cout << "no" << endl;
            return;
        }
        ass[i] = *it;
        rem.erase(it);
    }
    cout << "yes" << endl;
}

int main() {
    int t;
    cin >> t;
    while (t-->0)testcase();
}
