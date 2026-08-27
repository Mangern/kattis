#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nop(n, 0);

    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;

        for (int j = 0; j <  n; ++j) {
            if (s[j] == '(')++nop[j];
        }
    }

    vector<int> depth(n, 0);
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    for (int i = 0; i < n; ++i) {
        sort(begin(idx), end(idx), [&](auto a, auto b) {
            if (depth[a] == depth[b]) return a < b;
            return depth[a] < depth[b];
        });

        for (int j = 0; j < nop[i]; ++j) {
            ++depth[idx[j]];
        }
        for (int j = nop[i]; j < n; ++j) {
            if (depth[idx[j]] == 0) {
                cout << "No" << endl;
                return 0;
            }
            --depth[idx[j]];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (depth[i] != 0) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
