#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using tup = array<ll, 3>;

const int mxN = 105;

vector<ii> cells[mxN];
vector<tup> studs[mxN];

int main() {
    ll r, c, f, s, g;

    cin >> r >> c >> f >> s >> g;

    for (int i = 0; i < f; ++i) {
        ll k;
        cin >> k;

        for (int j = 0; j < k; ++j) {
            ll x, y;
            cin >> x >> y;
            cells[i].push_back({x, y});
        }
        sort(begin(cells[i]), end(cells[i]));
    }

    for (int i = 0; i < s; ++i) {
        ll x, y, d, fi;
        cin >> x >> y >> d >> fi;
        --fi;
        studs[fi].push_back({d, x, y});
    }

    vector<ll> ans;
    for (int i = 0; i < f; ++i) {
        ll t;
        cin >> t;
        sort(begin(studs[i]), end(studs[i]));

        vector<ll> dists;

        for (int j = 0; j < studs[i].size(); ++j) {
            ll dist = abs(studs[i][j][1] - cells[i][j][0]) + abs(studs[i][j][2] - cells[i][j][1]);
            dists.push_back(dist);
        }
        sort(begin(dists), end(dists));
        ll cur = accumulate(begin(dists), begin(dists) + t, 0LL);
        ans.push_back(cur);
    }

    sort(begin(ans),end(ans));
    cout << accumulate(begin(ans), begin(ans)+g, 0LL) << endl;
}
