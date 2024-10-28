#include <algorithm>
#include <bits/stdc++.h>
#include <chrono>
#include <cmath>
#include <random>
using namespace std;
using vi = vector<int>;

#define all(v) begin(v), end(v)

const int mxN = 1e3+1;
using ii = array<int,2>;

struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};

int n;

struct point {
    double x, y;
};

point p[mxN];
double dist[mxN][mxN];

void pre() {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            dist[i][j] = hypot(p[i].x - p[j].x, p[i].y - p[j].y);
        }
    }
}

double tour_weight(const vi& tour) {
    double ans = 0.0;
    for (int i = 1; i < n; ++i) {
        ans += dist[tour[i-1]][tour[i]];
    }
    ans += dist[tour[n-1]][tour[0]];
    return ans;
}

vi greedy() {
    vi tour(n, 0);
    vi vis(n, 0);
    vis[0] = 1;
    for (int i = 1; i < n; ++i) {
        int best = -1;

        for (int j = 0; j < n; ++j) {
            if (!vis[j] && (best == -1 || dist[tour[i-1]][j] < dist[tour[i-1]][best])) {
                best = j;
            }
        }
        tour[i] = best;
        vis[best] = 1;
    }
    return tour;
}

vi mst() {
    vector<pair<double, ii>> edges;
    UnionFind uf(n);

    for (int i = 0; i < n; ++i) for (int j = i + 1; j < n; ++j) {
        edges.push_back({dist[i][j], {i, j}});
    }
    sort(all(edges));

    vector<vi> tree(n, vi());
    for (auto& [w, pp] : edges) {
        auto [u, v] = pp;
        if (uf.join(u, v)) {
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
    }

    function<void(int, int, vi&)> dfs = [&] (int u, int cf, vi& tour) {
        tour.push_back(u);
        for (int v : tree[u]) if (v != cf) { 
            dfs(v, u, tour);
        }
    };
    vi ans;
    double aw = INFINITY;
    for (int i = 0; i < n; ++i) {
        vi tour;
        dfs(0, -1, tour);
        double w = tour_weight(tour);
        if (w < aw) {
            aw = w;
            ans = tour;
        }
    }
    return ans;
}

vi brute() {
    vi idx(n);
    iota(all(idx), 0);

    vi ret;
    double ans = INFINITY;

    do {
        double w = tour_weight(idx);
        if (w < ans) {
            ans = w;
            ret = idx;
        }
    } while (next_permutation(all(idx)));
    return ret;
}

vi random_perm() {
    vi idx(n);
    iota(all(idx), 0);
     
    std::random_device rd;
    std::mt19937 g(rd());
    shuffle(all(idx), g);
    return idx;
}

vi simanneal(double& w, bool use_greedy = 1) {
    vi best = use_greedy ? greedy() : random_perm();
    //iota(all(best), 0);
    double bestw = tour_weight(best);
    double T = 1000.0;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 1.0);

    auto coin = [&] (double wa, double wb) {
        double p = exp(- (wb - wa) / T);
        return dis(gen) < p;
    };

    double a= 0.999;
    vi s = best;
    double sw = bestw;
    auto start = chrono::steady_clock::now();
    srand(start.time_since_epoch().count());

    for (int i = 0; i < 1000000; ++i) {
        //int ia = rand() % (n - 1);
        //int ib = ia + 1 + (rand() % (n - 1 - ia));
        //assert (ib > ia);
        //assert (ib < n);
        int ia = rand() % n;
        int ib = ia;
        while (ib == ia)ib = rand() % n;
        double nw = sw;

        if ((ia + 1) % n == ib) {
            nw -= (dist[s[ia]][s[(ia - 1 + n) % n]]);
            nw -= (dist[s[ib]][s[(ib + 1) % n]]);
            nw += (dist[s[ib]][s[(ia - 1 + n) % n]]);
            nw += (dist[s[ia]][s[(ib + 1) % n]]);
        } else if ((ib + 1) % n == ia) {
            nw -= (dist[s[ia]][s[(ia + 1) % n]]);
            nw -= (dist[s[ib]][s[(ib - 1 + n) % n]]);
            nw += (dist[s[ia]][s[(ib - 1 + n) % n]]);
            nw += (dist[s[ib]][s[(ia + 1) % n]]);
        } else {
            nw -= (dist[s[ia]][s[(ia - 1 + n) % n]]);
            nw -= (dist[s[ia]][s[(ia + 1) % n]]);

            nw -= (dist[s[ib]][s[(ib - 1 + n) % n]]);
            nw -= (dist[s[ib]][s[(ib + 1) % n]]);

            nw += (dist[s[ib]][s[(ia - 1 + n) % n]]);
            nw += (dist[s[ib]][s[(ia + 1) % n]]);

            nw += (dist[s[ia]][s[(ib - 1 + n) % n]]);
            nw += (dist[s[ia]][s[(ib + 1) % n]]);
        }

        //vi nei = s;
        //swap(nei[ia], nei[ib]);

        //cout << nw << " " << tour_weight(nei) << " " << ia << " " << ib << endl;
        //break;

        if (nw < sw) {
            swap(s[ia], s[ib]);
            sw = nw;
            if (nw < bestw) {
                best = s;
                bestw = sw;
            }
        } else if (coin(sw, nw)) {
            swap(s[ia], s[ib]);
            sw = nw;
        }
        T = a * T;
    }
    w = bestw;
    return best;
}

vi multisim() {
    double answ;
    vi ans = simanneal(answ, 1);

    for (int i = 0; i < 100; ++i) {
        double rw;
        vi ret = simanneal(rw, 0);
        if (rw < answ) {
            answ = rw;
            ans = ret;
        }
    }
    return ans;
}

vi improvesim() {
    double answ;
    vi tour = simanneal(answ, 1);
    vector<pair<double, ii>> edg;

    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        edg.push_back({dist[tour[i]][tour[j]], {tour[i], tour[j]}});
    }
    sort(edg.rbegin(), edg.rend());

    set<int> banned;
    for (int i = 0; i < 8; ++i) {
        banned.insert(edg[i].second[0]);
    }
    vector<vi> segs;
    vi cur;
    int si;
    for (si = 0; ; ++si) if (banned.count(tour[si]))break;

    for (int i = (si + 1) % n; ; i = (i + 1) % n) {
        cur.push_back(tour[i]);
        if (banned.count(tour[i])) {
            segs.push_back(cur);
            cur.clear();
        }

        if (i == si)break;
    }

    int sm = 0;
    for (auto& v : segs)sm += v.size();
    assert(sm == n);
    vi idx(segs.size());
    iota(all(idx), 0);
    
    do {
        vi ntour;

        for (int i : idx) {
            for (auto x : segs[i])ntour.push_back(x);
        }
        double nw = tour_weight(ntour);
        if (nw < answ) {
            tour = ntour;
            answ = nw;
        }
    } while (next_permutation(all(idx)));

    return tour;
}

void gen() {
    cout << n << endl;
    for (int i = 0; i < n; ++i) {
        p[i].x = double(rand() % 100000000) / 1000.0;
        p[i].y = double(rand() % 100000000) / 1000.0;
        cout << p[i].x << " " << p[i].y << endl;
    }
    //vi ret = brute();

    //for (auto x : ret)cout << x << endl;

    //cout << tour_weight(ret) << endl;
}

int main() {
    cin >> n;

    //gen(); return 0;

    for (int i = 0; i < n; ++i) {
        cin >> p[i].x >> p[i].y;
    }

    pre();

    double tmp;
    vi ret = (n >= 10 ? improvesim() : brute());
    //ret = greedy();

    for (auto x : ret)cout << x << endl;

    //cout << setprecision(8) << fixed << tour_weight(ret) << endl;
}
