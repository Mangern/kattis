#include <bits/stdc++.h>
#include <iterator>
#include <queue>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;
using tup = array<ll, 3>;

ll calculate(ll n, ll m, vector<ii> segs) {
    ll offset = rand() % m;

    for (auto &[s, e] : segs) {
        s -= offset;
        e -= offset;
        s = (s % m + m) % m;
        e = (e % m + m) % m;
    }

    vector<tup> dub;

    for (int i = 0; i < n; ++i) {
        auto [s, e] = segs[i];
        if (s < e) {
            dub.push_back({s, e, i});
            dub.push_back({s + m, e + m, i});
        } else {
            dub.push_back({s, e + m, i});
            dub.push_back({0, e, i});
            dub.push_back({s + m, 2 * m, i});
        }
    }

    sort(begin(dub), end(dub));

    priority_queue<tup> pq;

    ll cur = 0;

    vector<tup> take;
    int ptr = 0;

    int good_mid = -1;
    ll end_good_mid = 0;

    while (cur < 2 * m) {
        while (ptr < dub.size() && dub[ptr][0] <= cur) {
            pq.push({dub[ptr][1], dub[ptr][0], dub[ptr][2]});
            ++ptr;
        }
        if (pq.empty() || pq.top()[0] <= cur) {
            return -1;
        }
        auto [e, s, i] = pq.top();
        pq.pop();

        take.push_back({s, e, i});
        cur = e;
    }

    for (auto [s, e, i] : take) {
        if (s <= m && m <= e && e > end_good_mid) {
            end_good_mid = e;
            good_mid = i;
        }
    }

    // cout << "This segment HAS to be in the solution: " << segs[good_mid][0] << " " << segs[good_mid][1] << endl;

    offset = segs[good_mid][0];

    for (auto &[s, e] : segs) {
        s -= offset;
        e -= offset;
        while (s < 0)s += m;
        while (e < s)e += m;
    }
    sort(begin(segs), end(segs));
    pq = priority_queue<tup>();

    ll ans =0;
    cur = 0;
    ptr = 0;

    // cout << "After offset" << endl;
    // for (auto [s, e] : segs) cout << s << " " << e << endl;

    while (cur < m) {
        while (ptr < segs.size() && segs[ptr][0] <= cur) {
            pq.push({segs[ptr][1], ptr, 0});
            ++ptr;
        }

        assert (pq.size());

        auto [e, i, _] = pq.top();
        pq.pop();

        assert(e > cur);

        ++ans;

        cur = e;
    }

    return ans;
}

int main() {
    ll n, m;
    cin >> n >> m;

    vector<ii> segs(n);
    for (int i = 0; i < n; ++i) {
        cin >> segs[i][0] >> segs[i][1];
    }

    ll ans = calculate(n, m, segs);
    ans = min(ans, calculate(n, m, segs));
    ans = min(ans, calculate(n, m, segs));

    cout << ans << endl;
}
