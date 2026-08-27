#include <bits/stdc++.h>
using namespace std;

using ii = array<int,3>;

int score(const string& a, const string& b) {
    int sm = 0;
    for (int i = 0; i < a.length(); ++i) {
        sm += (a[i] != b[i]);
    }
    return sm;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<string> a(n);
    for (auto& s : a)cin >> s;

    vector<int> par(n, -1);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    int ans = 0;

    pq.push({0, -1, 0});

    while (pq.size()) {
        auto [d, u, v] = pq.top();
        pq.pop();

        if (par[v] != -1)continue;

        par[v] = u;
        ans += d;

        for (int i = 1; i < n; ++i) {
            if (par[i] == -1) {
                pq.push({score(a[v], a[i]), v, i});
            }
        }
    }

    cout << ans << endl;

    for (int i = 1; i < n; ++i) {
        cout << par[i] << " " << i << endl;
    }
}
