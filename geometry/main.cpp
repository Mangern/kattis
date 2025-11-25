#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

void compress(vector<ii>& poly) {
    int n = poly.size();
    set<ll> hitx, hity;

    for (int i = 0; i < n; ++i) {
        int nxt = (i+1)%n;

        if (poly[nxt][0] == poly[i][0]) {
            hitx.insert(poly[i][0]);
        } else {
            hity.insert(poly[i][1]);
        }
    }

    map<ll, ll> remapx, remapy;
    ll x = 0, y = 0;
    for (auto xx : hitx) {
        remapx[xx] = x++;
    }
    for (auto yy : hity) {
        remapy[yy] = y++;
    }

    vector<ii> tmp(poly.size());

    for (int i = 0; i < n; ++i) {
        auto [x, y] = poly[i];
        tmp[i] = {remapx[x], remapy[y]};
    }

    int mini = 0;

    for (int i = 1; i < n; ++i) {
        if (tmp[i] < tmp[mini])mini = i;
    }

    int ptr = 0;
    for (int i = mini;i < n; ++i) {
        poly[ptr++] = tmp[i];
    }
    for (int i = 0; i < mini; ++i) {
        poly[ptr++] = tmp[i];
    }
}

vector<ii> rot90(const vector<ii> &poly) {
    vector<ii> res;
    res.reserve(poly.size());
    for (auto [x, y] : poly) {
        res.push_back({-y, x});
    }
    compress(res);
    return res;
}

int main() {

    ll n, m;
    cin >> n;
    vector<ii> pa(n);
    for (int i = 0; i < n; ++i) {
        cin >> pa[i][0] >> pa[i][1];
    }
    cin >> m;
    vector<ii> pb(m);
    for (int i = 0; i < m; ++i) {
        cin >> pb[i][0] >> pb[i][1];
    }

    compress(pa);
    compress(pb);

    if (pa == pb) {
        cout << "yes" << endl;
        return 0;
    }

    // cout << "Before rot: " << endl;
    // for (auto [x, y] : pb) {
    //     cout << "  " << x << " " << y << endl;
    // }

    pb = rot90(pb);

    // cout << "After rot: " << endl;
    // for (auto [x, y] : pb) {
    //     cout << "  " << x << " " << y << endl;
    // }

    if (pa == pb) {
        cout << "yes" << endl;
        return 0;
    }
    pb = rot90(pb);
    if (pa == pb) {
        cout << "yes" << endl;
        return 0;
    }
    pb = rot90(pb);
    if (pa == pb) {
        cout << "yes" << endl;
        return 0;
    }
    cout << "no" << endl;
}
