#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = numeric_limits<ll>::max() / 8;

using Point = array<ll, 4>;

ll key(const Point& pt) {
    return pt[0] * 400 * 400 * 400 + pt[1] * 400 * 400 + pt[2] * 400 + pt[3];
}

struct Hash {
    ll operator()(const Point& pt) const {
        return key(pt);
    }
};

ll dist(const Point& a, const Point& b) {
    ll d = 0;
    for (int i = 0; i < 4; ++i) {
        d += abs(a[i] - b[i]);
    }
    return d;
}

ll heur(const Point& node, const Point& goal) {
    ll h = 0;
    for (int i = 0; i < 4; ++i) {
        ll d = abs(node[i] - goal[i]);
        ll mul = 1;
        for (int j = 0; j < 3 - i; ++j)mul *= 400;
        h += mul * d;
    }
    return h;
}

vector<Point> neighbors(const Point& pt) {
    auto [x, y, z, w] = pt;
    vector<Point> neis;
    neis.push_back({x-1, y, z, w});
    neis.push_back({x+1, y, z, w});
    neis.push_back({x, y-1, z, w});
    neis.push_back({x, y+1, z, w});
    neis.push_back({x, y, z-1, w});
    neis.push_back({x, y, z+1, w});
    neis.push_back({x, y, z, w-1});
    neis.push_back({x, y, z, w+1});
    return neis;
}

int main() {
    int n;
    cin >> n;

    vector<Point> rooms(n);
    for (int i = 0; i < n; ++i) {
        for (int j =0; j < 4; ++j) {
            cin >> rooms[i][j];
        }
    }

    sort(begin(rooms), end(rooms));

    vector<Point> entrance(n);

    for (int i = 0; i < n; ++i) {
        Point pt = rooms[i];

        if (pt[0] > 200) {
            --pt[0];
        } else {
            ++pt[0];
        }
        entrance[i] = pt;
    }

    unordered_set<Point, Hash> tree;
    unordered_set<Point, Hash> blocked;

    const int STATUS_LEGAL = 0;
    const int STATUS_ILLEGAL = 1;
    const int STATUS_TREE = 2;

    auto is_illegal = [&] (const Point& p) {
        if (blocked.count(p)) return STATUS_ILLEGAL;

        int num_tree_nei = 0;
        for (auto nei : neighbors(p)) {
            if (tree.count(nei))++num_tree_nei;
        }
        if (num_tree_nei > 1) return STATUS_ILLEGAL;
        if (num_tree_nei == 1) return STATUS_TREE;

        ll minc = 400, maxc = -1;
        for (int i = 0; i< 4; ++i) {
            minc = min(minc, p[i]);
            maxc = max(maxc, p[i]);
        }
        if (minc < 0 || maxc >= 400) return STATUS_ILLEGAL;
        return STATUS_LEGAL;
    };

    for (int i = 0; i < n; ++i) {
        blocked.insert(rooms[i]);
        for (const auto &block : neighbors(rooms[i])) {
            blocked.insert(block);
        }
    }
    tree.insert(rooms[0]);
    tree.insert(entrance[0]);
    blocked.erase(entrance[0]);

    for (int i = 1; i < n; ++i) {
        ll mind = INF;
        int goal_room = 0;
        for (int j = 0; j < i; ++j) {
            ll here = dist(rooms[j], rooms[i]);
            if (here < mind) {
                mind = here;
                goal_room = j;
            }
        }
        Point goal_point = entrance[goal_room];
        unordered_map<Point, Point, Hash> came_from;
        unordered_map<Point, ll, Hash> dist;
        unordered_map<Point, ll, Hash> heuristic;
        using State = tuple<ll, ll, Point>;
        priority_queue<State, vector<State>, greater<State>> pq;
        dist[entrance[i]] = 0;
        heuristic[entrance[i]] = heur(entrance[i], goal_point);
        pq.push({heuristic[entrance[i]], dist[entrance[i]], entrance[i]});

        while (pq.size()) {
            auto [h, d, u] = pq.top();
            pq.pop();
            if (dist[u] < d) continue;

            if (u == goal_point) break;
            // TODO: check if we can exit

            bool done=false;
            for (const Point& v : neighbors(u)) {
                int status = is_illegal(v);
                if (status == STATUS_ILLEGAL) continue;
                if (status == STATUS_TREE) {
                    // cout << "Hit tree: ";
                    // for (int i = 0; i < 4; ++i)cout << v[i] << ' ';
                    // cout << endl;
                    came_from[v] = u;
                    goal_point = v;
                    done = true;
                    break;
                }
                if (!dist.count(v) || d + 1 < dist[v]) {
                    dist[v] = d + 1;
                    heuristic[v] = heur(v, goal_point);
                    came_from[v] = u;
                    pq.push({heuristic[v], dist[v], v});
                }
            }
            if (done) break;
        }

        Point ptr = goal_point;
        while (true) {
            tree.insert(ptr);
            if (!came_from.count(ptr)) break;
            ptr = came_from[ptr];
        }

        tree.insert(rooms[i]);
    }

    cout << tree.size() << endl;
    vector<Point> output(begin(tree), end(tree));
    sort(begin(output), end(output));
    for (auto [x, y, z, w] : output) {
        cout << x << " " << y << " " << z << " " << w << '\n';
    }
}
