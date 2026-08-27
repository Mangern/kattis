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

// t should support min-function (operator <)
template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

// t should support max-function (operator <)
template<typename t>
t max(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = max(ans, el);
    }
    return ans;
}
const int mxN = 1e5+3;

int n,q;
int p[mxN];
int sz[mxN];
int rnk[mxN];
ll sm[mxN];
set<int> child[mxN];

int parent(int i) {
    if (p[i] == i)return i;
    int res = parent(p[i]);

    child[p[i]].erase(i);
    child[res].insert(i);
    p[i] = res;
    return res;
}

void join(int i, int j) {
    i = parent(i);
    j = parent(j);

    if (i == j)return;

    if (sz[i] < sz[j])swap(i,j);

    p[i] = j;
    child[j].insert(i);
    sm[j] += sm[i];
    sz[j] += sz[i];
}

void move(int i, int j) {
    j = parent(j);

    int np = p[i];
    if (parent(np) == j)return;

    if (np == i && !child[i].empty()) {
        np = *child[i].begin();
        child[i].erase(np);
        sm[np] = sm[i];
        sz[np] = sz[i];
        p[np] = np;
    }
    for (auto x : child[i]) {
        child[np].insert(x);
        p[x] = np;
    }
    child[np].erase(i);
    child[i] = set<int>();
    np = parent(np);
    sm[np] -= (i+1);
    sz[np] -= 1;
    sm[i] = i+1;
    sz[i] = 1;

    p[i] = j;
    sm[j] += (i+1);
    sz[j] += 1;
    child[j].insert(i);
}

bool testCase() {
    if (!(cin >> n))return false;
    cin >> q;

    for (int i = 0; i < n; ++i) {
        p[i] = i;
        child[i] = set<int>();
        sz[i] = 1;
        sm[i] = i+1;
        rnk[i] = 0;
    }

    while (q-->0) {
        int t;
        cin >> t;

        if (t == 1) {
            int u,v;
            cin >> u >> v, --u, --v;
            join(u,v);
        } else if (t == 2) {
            int u,v;
            cin >> u >> v, --u, --v;
            move(u,v);
        } else {
            int u;
            cin >> u, --u;
            u = parent(u);
            cout << sz[u] << " " << sm[u] << endl;
        }
    }
    return true;
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

    while (testCase()){}
    return 0;
}
