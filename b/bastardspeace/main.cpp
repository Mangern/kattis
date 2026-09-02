#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll,ll>;

int main() {
    int n;
    ll s;
    cin >> n >> s;

    vector<deque<ii>> qs(n);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            qs[i].push_back({x, 0});
        }
        for (int j = 0; j < m; ++j) {
            ll x;
            cin >> x;
            qs[i][j].second = x;
        }
        pq.push({qs[i][0].first, i});
    }

    while (pq.size()) {
        auto [thresh, qi] = pq.top();
        if (thresh >= s) break;
        pq.pop();

        auto& q = qs[qi];
        s += q.front().second;
        q.pop_front();
        if (q.size()) {
            pq.push({q.front().first, qi});
        }
    }

    if (pq.empty()) {
        cout << "Sigur!" << endl;
    } else {
        cout << s << endl;
    }
}
