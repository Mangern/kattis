#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;
using ld = long double;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (unsigned ll)rng() % B;
}
template<typename t>
istream& operator >> (istream& in, vector<t>& vec) {
    for (t& x : vec)in >> x;
    return in;
}

template<typename t>
ostream& operator << (ostream& out, vector<t>& vec) {
    int n = (int)vec.size();
    for (int i = 0; i < n; ++i) {
        out << vec[i];
        if (i < n - 1)out << " ";
    }
    return out;
}

template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 3e4+3;

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

bool testCase() {
    int n, m;
    cin >> n >> m;
    if (!(n|m))return 0;

    vector<vi> adj(n, vi());
    vi in(n,0);
    vi out(n,0);
    UnionFind uf(n);

    for (int i = 0; i < m; ++i) {
        int u,v;
        cin >> u >> v;
        adj[u].push_back(v);
        ++out[u];
        ++in[v];
        uf.join(u,v);
    }

    if (uf.num_sets > 1) {
        cout << "Impossible" << endl;
        return 1;
    }

    int cntne = 0;
    int s = -1;
    int t = -1;
    for (int i = 0; i < n; ++i) {
        if (in[i] == out[i])continue;
        if (in[i] == out[i]+1 && t == -1) {
            t = i;
        } else if (out[i] == in[i]+1 && s == -1) {
            s = i;
        } else {
            cout << "Impossible" << endl;
            return 1;
        }
    }

    if (s != -1 && t != -1) {
        adj[t].push_back(s);
    } else if (!(s == -1 && t == -1)) {
        cout << "Impossible" << endl;
        return 1;
    }


    function<void(int, vi&)> find_path = [&] (int u, vi& path) {
        path.push_back(u);
        if (path.size() > 1 && path[0] == path.back())return;

        int v = adj[u].back();
        adj[u].pop_back();
        find_path(v, path);
    };

    vi buf;
    find_path(0, buf);

    list<int> path;

    for (auto x : buf)path.push_back(x);

    auto print_path = [&] () {
        for (auto x : path)cout << x << " ";
        cout << endl;
    };

    //print_path();
    while (path.size() < m + 1) {
        auto it = begin(path);
        for (; it != end(path); ++it) {
            if (adj[*it].size())break;
        }
        buf = vi();
        find_path(*it, buf);
        ++it;
        for (int i = 1; i < buf.size(); ++i) {
            int x =buf[i];
            it = path.insert(it, x);
            ++it;
        }
        //print_path();
    }

    vi ans(begin(path), end(path));
    vi ans2;

    if (s != -1) {
        int i;
        for (i = 1; i < m+1; ++i) {
            if (ans[i-1] == t && ans[i] == s)break;
        }

        for (int j = i; j < m + 1; ++j)ans2.push_back(ans[j]);
        for (int j = 0; j < i; ++j)ans2.push_back(ans[j]);
    } else ans2 = ans;

    cout << ans2 << endl;

    return 1;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    while (testCase());
    return 0;
}
