#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, p;
    cin >> n >> p;

    vector<stack<int>> piles(p);

    for (int i = 0; i < p; ++i) {
        int k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            int x;
            cin >> x;

            piles[i].push(x);
        }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        int s, d, cnt;
        cin >> s >> d >> cnt, --s, --d;

        stack<int> dmp;
        for (int j = 0; j < cnt; ++j) {
            dmp.push(piles[s].top());
            piles[s].pop();
        }
        while (dmp.size()) {
            piles[d].push(dmp.top());
            dmp.pop();
        }
    }

    for (int i = 0; i < p; ++i) {
        stack<int> dmp;
        while (piles[i].size()) {
            dmp.push(piles[i].top());
            piles[i].pop();
        }
        while (dmp.size()) {
            cout << dmp.top() << " ";
            dmp.pop();
        }
        cout << endl;
    }
}
