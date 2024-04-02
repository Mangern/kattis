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
    return max(max(s[0], t[0]) - min(s[0], t[0]), max(s[1], t[1]) - min(s[1], t[1]));
}

ll sign(ll x) {
    if (x == 0)return 0;
    if (x < 0)return -1;
    return 1;
}

bool ontheway(array<ll,2> s, array<ll,2> t, array<ll,2> point) {
    ll dir_x = sign(t[0] - s[0]);
    ll dir_y = sign(t[1] - s[1]);
    ll dist_point = dist(s, point);
    ll dist_goal = dist(s, t);
    if (dist_point > dist_goal)return false;
    if (point[0] != s[0] + dir_x * dist_point)return false;
    if (point[1] != s[1] + dir_y * dist_point)return false;
    return true;
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

    for (int i = 0; i < q; ++i) {
        if (skip[i])continue;
        curr_t = max(curr_t, queries[i][0]);

        ll d = dist({curr_x, curr_y}, {queries[i][1], queries[i][2]});

        map<ll, waypoint> waypoints; // dist -> waypoint
        waypoints[0] = {curr_t, {curr_x, curr_y}, -1};
        waypoints[d] = {curr_t + d, {queries[i][1], queries[i][2]}, i};

        int j;
        for(j = i+1; j < q; ++j) {
            if (skip[j])continue;
            ll dist_to_query = dist({curr_x, curr_y}, {queries[j][1], queries[j][2]});
            auto it = waypoints.upper_bound(dist_to_query);
            if (it == waypoints.end())continue;
            if (queries[j][0] >= curr_t + d)break;

            auto before = prev(it);
            ll arrival_time = before->second.time + dist(before->second.point, {queries[j][1], queries[j][2]});
            if (ontheway(before->second.point, it->second.point, {queries[j][1], queries[j][2]}) &&
                arrival_time >= queries[j][0]) {

                //cout << queries[j][1] << " " << queries[j][2] << " on the way from ";
                //cout << before->second.point[0] << " " << before->second.point[1] << " to ";
                //cout << it->second.point[0] << " " << it->second.point[1] << endl;
                //cout << "    Arrive at " << arrival_time << endl;
                //cout << "    Spawn at " << queries[j][0] << endl;

                waypoints[dist_to_query] = {
                    arrival_time,
                    {queries[j][1], queries[j][2]},
                    j
                };
            }
        }

        for (auto [k, p] : waypoints) {
            if (p.query_index != -1) {
                ans.push_back({p.time, p.point[0], p.point[1]});
                skip[p.query_index] = true;
            }
        }

        curr_x = queries[i][1];
        curr_y = queries[i][2];
        curr_t += d;
    }

    for (auto [t, x, y] : ans) {
        cout << t << " " << x << " " << y << endl;
    }

    return 0;
}
