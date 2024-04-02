#include <bits/stdc++.h>
#include <iterator>
using namespace std;
using ll = long long;

struct waypoint {
    ll time;
    array<ll,2> point;
    int query_index;
};

ll dist(array<ll,2> s, array<ll,2> t) {
    return max(abs(s[0] - t[0]), abs(s[1] - t[1]));
}

bool ontheway(array<ll,2> s, array<ll,2> t, array<ll,2> point) {
    return dist(s, t) == dist(s, point) + dist(point, t);
}

int main() {
    ll n, m, q;
    cin >> n >> m >> q;

    vector<array<ll,4>> queries(q);

    for (int i = 0; i < q; ++i) {
        cin >> queries[i][0] >> queries[i][1] >> queries[i][2];
        queries[i][3] = i;
    }

    vector<bool> skip(q, 0);

    vector<array<ll,3>> ans;

    ll curr_x = 0, curr_y = 0;
    ll curr_t = 0;

    for (auto [t, x, y, i] : queries) {
        curr_t = max(curr_t, t);

        ll d = dist({curr_x, curr_y}, {x, y});

        curr_x = x;
        curr_y = y;
        curr_t += d;

        ans.push_back({curr_t, curr_x, curr_y});
    }

    for (auto [t, x, y] : ans) {
        cout << t << " " << x << " " << y << endl;
    }

    return 0;
}
