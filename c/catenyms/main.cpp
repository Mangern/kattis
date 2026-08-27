#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
template<typename t, size_t N>
using ar = array<t, N>;
using ii = ar<ll, 2>;
using vii = vector<ii>;
using vll = vector<ll>;

template<typename t>
istream& operator>>(istream& in, vector<t>& vec) {
    for (t& x : vec) {
        in >> x;
    }
    return in;
}

template<typename t>
ostream& operator<<(ostream& os, vector<t>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << " ";
    }
    return os;
}
#define all(v) begin(v), end(v)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (uint64_t)rng() % B;
}

template<typename t>
t min(const vector<t>& v) {
    return *min_element(all(v));
}

template<typename t>
t max(const vector<t>& v) {
    return *max_element(all(v));
}
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();
const int mxN = 1e3+6;
const ll MOD  = 1e9+7;

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
vi adj[26];
vi wdid[26];
int in[26];
string wrd[mxN];

// -1: no euler trail
//  u: node suitable to start euler trail
int eulernode() {
    int onemore = -1;
    int oneless = -1;
    int some_good = -1;
    UnionFind uf(26);
    for (int i = 0; i < 26; ++i) {
        if (adj[i].size() > 1 + in[i]) return -1;
        if (in[i] > 1 + adj[i].size()) return -1;
        if (adj[i].size() == 1 + in[i]) {
            if (onemore != -1)return -1;
            onemore = i;
        } else if (adj[i].size() + 1 == in[i]) {
            if (oneless != -1)return -1;
            oneless = i;
        }

        for (int j : adj[i]) {
            uf.join(i, j);
        }

        if (some_good == -1 && adj[i].size())some_good = i;
    }
    set<int> nbig;
    for (int i = 0; i < 26; ++i) {
        int p = uf.find(i);
        if (uf.sz[p] > 1)nbig.insert(p);
    }
    if (nbig.size() > 1)return -1;
    if (onemore != -1)return onemore;
    return some_good;
}

void testCase() {
    for (int i = 0; i < 26; ++i) {
        adj[i].clear();
        in[i] = 0;
        wdid[i].clear();
    }

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> wrd[i];
    }

    sort(wrd, wrd+n);
    for (int i = 0; i < n; ++i) {

        adj[wrd[i][0]-'a'].push_back(wrd[i].back()-'a');
        wdid[wrd[i][0]-'a'].push_back(i);
        ++in[wrd[i].back()-'a'];
        //cout << (int)(wrd[i][0]-'a') << " " << (int)(wrd[i].back()-'a') << " " << wrd[i] << endl;
    }

    int start = eulernode();
    if (start == -1) {
        cout << "***" << endl;
        return;
    }
    vector<string> ans;
    vi idx(26, 0);
    vi st;
    vi st2;
    st.push_back(start);
    while (st.size()) {
        int u = st.back();
        if (idx[u] < adj[u].size()) {
            st.push_back(adj[u][idx[u]]);
            st2.push_back(wdid[u][idx[u]]);
            ++idx[u];
        } else {
            if (st2.size())ans.push_back(wrd[st2.back()]);
            st.pop_back();
            st2.pop_back();
        }
    }

    while (ans.size()) {
        cout << ans.back();
        if (ans.size() == 1)cout << endl;
        else cout << ".";
        ans.pop_back();
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
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
        //if (tc == 5)break;
    }
    return 0;
}
