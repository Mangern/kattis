#include <bits/stdc++.h>
using namespace std;

int main() {
    int p, t;
    cin >> p >> t;

    vector<vector<int>> ops(p);
    for (int i = 0; i < t * p; ++i) {
        int a, b;
        if (!(cin >> a)) break;
        cin >> b;
        --a;
        ops[a].push_back(b);
    }
    for (int i = 0; i < p; ++i) sort(begin(ops[i]), end(ops[i]));

    sort(begin(ops), end(ops));

    ops.erase(unique(begin(ops), end(ops)), end(ops));
    cout << ops.size() << endl;
}
