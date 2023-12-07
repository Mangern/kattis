#include <queue>
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
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
struct UnionFind {
    vi p, rnk;
    int num_sets;
    UnionFind(int n) {
        p = vi(n);
        num_sets = n;
        iota(all(p),0);
        rnk = vi(n,0);
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
            p[i] = j;
        } else {
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};
const int mxN = 2501;
const int mxM = 3223800;

struct Edge {
    ll w;
    int u;
    int v;

    bool operator<(const Edge& other) const {
        return w > other.w;
    }
};

ll weight[mxN][mxN];

void testCase() {
    int n;
    cin >> n;
    int m = (n * (n - 1))>>1;

    // n - 1 els, 
    // n-2 els
    //

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> weight[i][j];
        }
    }

    UnionFind uf(n);

    priority_queue<Edge> pq;

    set<int> out;
    for (int j = 1; j < n; ++j) {
        pq.push({weight[0][j], 0, j});
        out.insert(j);
    }


    while (pq.size() && uf.num_sets > 1) {
        auto e = pq.top();
        int u = e.u;
        int v = e.v;
        pq.pop();
        if (!uf.join(u, v))continue;
        cout << u+1 << " " << v+1 << "\n";
        out.erase(v);
        for (int z : out) {
            pq.push({weight[v][z], v, z});
        }
    }
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
}

int main() {
    setIO();
    pre();
    int t = 1;
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
