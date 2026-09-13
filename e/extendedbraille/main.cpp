#include <bits/stdc++.h>
using namespace std;
using ii = array<int, 2>;

int main() {
    int n;
    cin >> n;

    vector<vector<ii>> brailles(n);

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        for (int j = 0; j < m; ++j) {
            int x, y;
            cin >> x >> y;
            brailles[i].push_back({x, y});
        }

        int minx = brailles[i][0][0];
        int miny = brailles[i][0][1];

        for (auto [x, y] : brailles[i]) {
            minx = min(minx, x);
            miny = min(miny, y);
        }

        for (auto &[x, y] : brailles[i]) {
            x -= minx;
            y -= miny;
        }
        sort(begin(brailles[i]), end(brailles[i]));
    }
    sort(begin(brailles), end(brailles));

    auto cnt = unique(begin(brailles), end(brailles)) - begin(brailles);
    cout << cnt << endl;
}
