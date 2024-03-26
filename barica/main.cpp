#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;

using ll = long long;
using ii = array<int,2>;

const int mxN = 3e5+5;
const int mxX = 1e5+5;


int n;
ll k;

ii itoc[mxN];
ll flie[mxN];
ll cost[mxN];
int cf[mxN];

ll row_best[mxN];
int row_besti[mxN];
ll col_best[mxN];
int col_besti[mxN];

using tup = array<int,3>;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;

    vector<tup> nodes;

    for (int i = 0; i < n; ++i) {
        cost[i] = -1000000000L;
        int& x = itoc[i][0];
        int& y = itoc[i][1];
        cin >> x >> y >> flie[i];

        nodes.push_back({x, y, i});
    }

    sort(nodes.begin(), nodes.end(), [&] (auto a, auto b) {
        return ii{a[0]+a[1], a[2]} < ii{b[0]+b[1], b[2]};
    });

    col_best[itoc[0][0]] = flie[0];
    col_besti[itoc[0][0]] = 0;
    row_best[itoc[0][1]] = flie[0];
    row_besti[itoc[0][1]] = 0;
    cost[0] = flie[0];

    for (const auto& [x, y, i] : nodes) {
        if (x < itoc[0][0])continue;
        if (y < itoc[0][1])continue;
        if (x > itoc[n-1][0])continue;
        if (y > itoc[n-1][1])continue;
        if (i == 0)continue;

        ll score_col = col_best[x] - k;
        ll score_row = row_best[y] - k;

        if (max(score_col, score_row) < 0)continue;

        if (score_col > score_row) {
            cf[i] = col_besti[x];
            cost[i] = score_col + flie[i];
        } else {
            cf[i] = row_besti[y];
            cost[i] = score_row + flie[i];
        }

        if (cost[i] > col_best[x]) {
            col_best[x] = cost[i];
            col_besti[x] = i;
        }
        if (cost[i] > row_best[y]) {
            row_best[y] = cost[i];
            row_besti[y] = i;
        }
    }

    vector<ii> ans;
    int ptr = n - 1;

    while (ptr != 0) {
        ans.push_back(itoc[ptr]);
        ptr = cf[ptr];
    }
    ans.push_back({itoc[0]});
    cout << cost[n-1] << endl;
    cout << ans.size() << endl;

    while (ans.size()) {
        cout << ans.back()[0] << " " << ans.back()[1] << endl;
        ans.pop_back();
    }
    return 0;
}
