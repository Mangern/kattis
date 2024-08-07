#pragma GCC optimize("Ofast", "unroll-loops")
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
struct UnionFind {
    vi p, rnk;
    UnionFind(int n) {
        p = vi(n);
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
        return 1;
    }
};
const int mxN = 3e4+3;

void testCase() {
    int n;
    cin >> n;
    vector<ar<ll,3>> edge;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            ll w;
            cin >> w;
            if (j > i) {
                edge.push_back({w,i,j});
            }
        }
    }

    sort(all(edge));

    UnionFind uf(n);

    for (auto [w,u,v] : edge) {
        if (uf.join(u,v)) {
            cout <<u+1 << " " << v+1 << "\n";
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
