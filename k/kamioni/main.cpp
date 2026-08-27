#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct event {
    int truck;
    ll time;
    ll pos;
    int dir;

    bool operator<(const event& other) const {
        return (time == other.time ? truck < other.truck : time < other.time);
    }
};

struct query {
    int match_truck;
    int delta_dir;
};

const int mxN = 1e5+5;

int n, q;
vector<event> events;
int evt_count[mxN];
ll pos[mxN];
ll upd_time[mxN];
int dir[mxN];
bool done[mxN];
vector<query> match[mxN];

int main() {
    cin >> n >> q;

    for (int i = 0; i < n; ++i) {
        cin >> evt_count[i];

        ll ap, a;
        ll time = 0;
        for (int j = 0; j < evt_count[i]; ++j) {
            cin >> a;

            if (j > 0) {
                events.push_back({
                    i,
                    time,
                    ap,
                    a > ap ? 1 : -1,
                });
                time += abs(ap - a);
            }
            if (j == 1) {
                dir[i] = (a > ap ? 1 : -1);
                pos[i] = ap;
                upd_time[i] = 0;
            }
            ap = a;
        }
        events.push_back({i, time, ap, 0}); // dir of 0 makes it disappear
    }

    sort(events.begin(), events.end());

    vector<pair<int,int>> queries;
    map<pair<int,int>, int> ans;

    for (int i = 0; i < q; ++i) {
        int a, b;
        cin >> a >> b, --a, --b;

        queries.push_back({a,b});

        if (a > b)swap(a,b);

        if (ans.count({a,b}))continue;
        ans[{a,b}] = 0;

        if (evt_count[a] <= evt_count[b]) {
            match[a].push_back(query{b, pos[b] < pos[a] ? -1 : 1});
        } else {
            match[b].push_back(query{a, pos[a] < pos[b] ? -1 : 1});
        }
    }

    for (const auto& evt : events) {
        ll p_time = upd_time[evt.truck];
        int p_dir = dir[evt.truck];

        dir[evt.truck] = evt.dir;
        pos[evt.truck] = evt.pos;
        upd_time[evt.truck] = evt.time;

        for (auto& q : match[evt.truck]) {
            int n_dir = 0;
            int other_truck = q.match_truck;
            if (dir[other_truck] == 0 && p_time >= upd_time[other_truck])n_dir = 0;
            else {
                ll my_pos;
                ll other_pos = pos[other_truck] + dir[other_truck] * (evt.time - upd_time[other_truck]);
                if (dir[other_truck] == 0) {
                    my_pos = evt.pos + (evt.time - upd_time[other_truck]) * (-p_dir);
                } else {
                    my_pos = evt.pos;
                }
                n_dir = (my_pos < other_pos ? 1 : -1);
            }

            if (q.delta_dir * n_dir == -1)++ans[{min(evt.truck, other_truck), max(evt.truck, other_truck)}];
            q.delta_dir = n_dir;
        }
    }

    for (auto [a, b] : queries) {
        cout << ans[{min(a,b), max(a,b)}] << endl;
    }

    return 0;
}
