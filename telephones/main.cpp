#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll, 2>;

enum class event_type {
    CALL_START,
    CALL_END,
    QUERY_START,
    QUERY_END
};

struct event {
    event_type type;
    ll data;
    ll idx;

    bool operator<(const event& other) const {
        if (data != other.data) return data < other.data;

        if (type == event_type::CALL_END || type == event_type::QUERY_END) {
            return true;
        }
        return false;
    }
};

int main() {
    for (;;) {
        int n, m;
        cin >> n >> m;

        if (!n) break;

        vector<event> evts;
        for (int i = 0; i < n; ++i) {
            ll tmp, a, b;
            cin >> tmp >> tmp >> a >> b;

            evts.push_back({event_type::CALL_START, a, (ll)i});
            evts.push_back({event_type::CALL_END, a+b, (ll)i});
        }

        for (int i = 0; i < m; ++i) {
            ll a, b;
            cin >> a >> b;

            evts.push_back({event_type::QUERY_START, a, i});
            evts.push_back({event_type::QUERY_END, a+b, i});
        }

        sort(begin(evts), end(evts));

        vector<ll> ans(m, 0);
        vector<ll> save(m, 0);
        ll ncall = 0;
        ll nstart = 0;
        ll nend = 0;
        for (auto [t, dat, idx] : evts) {
            switch (t) {
            case event_type::CALL_START:
                {
                    ++nstart;
                    ++ncall;
                }
                break;
            case event_type::CALL_END:
                {
                    ++nend;
                    --ncall;
                }
                break;
            case event_type::QUERY_START:
                {
                    ans[idx] = ncall;
                    save[idx] = nstart;
                }
                break;
            case event_type::QUERY_END:
                {
                    ll new_started = nstart - save[idx];
                    ans[idx] += new_started;
                }
                break;
              break;
            }
        }

        for (int i = 0; i < m; ++i) cout << ans[i] << endl;
    }
}
