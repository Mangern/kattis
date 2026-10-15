#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e6+6;
int cnt[mxN];

int main() {
    int n, h;
    cin >> n >> h;

    for (int i = 0; i < n; ++i) {
        int v;
        cin >> v;
        ++cnt[v];
    }
    using ii = pair<int, int>;
    priority_queue<ii> pq;
    for (int v = 1; v < mxN; ++v) {
        if (cnt[v] > 0) {
            pq.push({cnt[v], v});
        }
    }

    vector<vector<int>> ans;

    while (pq.size() >= h) {
        vector<int> here;
        for (int i = 0; i < h; ++i) {
            auto [c, v] = pq.top();
            pq.pop();
            here.push_back(v);
            --cnt[v];
        }
        for (int v : here) if (cnt[v]) pq.push({cnt[v], v});
        ans.push_back(here);
    }

    if (ans.empty())cout << "impossible" << endl;
    else {
        for (const auto& row : ans) {
            for (auto x : row)cout << x << ' ';
            cout << endl;
        }
    }
}
