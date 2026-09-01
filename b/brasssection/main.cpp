#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, g;
    cin >> n >> g;
    vector<int> ans(n+1, -1);
    vector<vector<int>> groups(g);
    vector<vector<int>> belong(n+1);

    vector<int> sz(g, 0), num_neg(g, 0);

    queue<int> q;
    for (int i = 0; i < g; ++i) {
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;
            groups[i].push_back(x);
            ++sz[i];
            if (x < 0)++num_neg[i];

            belong[abs(x)].push_back(i);
        }

        if (k == 1) {
            q.push(i);
        }
    }

    while (q.size()) {
        int gi = q.front();
        q.pop();

        bool sat = 0;
        int undec = n + 10;
        for (auto x : groups[gi]) {
            int i = abs(x);
            if (ans[i] == 0 && x < 0 || ans[i] == 1 && x > 0) {
                sat = 1;
            }
            if (ans[i] < 0) {
                undec = x;
            }
        }
        if (sat) continue;
        if (undec == n + 10) {
            cout << "impossible" << endl;
            return 0;
        }
        if (undec < 0) {
            ans[abs(undec)] = 0;
        } else {
            ans[abs(undec)] = 1;
        }

        for (int i : belong[abs(undec)]) {
            if (--sz[i] == 1) {
                q.push(i);
            }
        }
    }
    cout << "possible" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << (ans[i] ? "L" : "Q");
    }
    cout << endl;
}
