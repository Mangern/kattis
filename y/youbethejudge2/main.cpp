#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int n;
    cin >> n;

    int sz = 1<<n;

    int mx = ((1<<(2*n)) - 1) / 3 + 1;

    vector<vector<pair<int,int>>> locs(mx);

    for (int i = 0; i < sz; ++i) {
        for (int j = 0; j < sz; ++j) {
            int x;
            cin >> x;
            locs[x].emplace_back(i, j);
        }
    }

    if (locs[0].size() != 1) {
        cout << 0 << endl;
        return 0;
    }

    for (int x = 1; x < mx; ++x) {
        if (locs[x].size() != 3) {
            cout << 0 << endl;
            return 0;
        }
        auto [i1, j1] = locs[x][0];
        auto [i2, j2] = locs[x][1];
        auto [i3, j3] = locs[x][2];
        int mini = min(min(i1,i2),i3);
        int minj = min(min(j1,j2),j3);
        i1 -= mini;
        i2 -= mini;
        i3 -= mini;
        j1 -= minj;
        j2 -= minj;
        j3 -= minj;
        if (max(max(i1,i2),i3) > 1 || max(max(j1,j2),j3) > 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    cout << 1 << endl;
}
