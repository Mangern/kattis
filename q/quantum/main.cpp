#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();

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

ll modpow(ll x, ll y, ll m) {
    if (y == 0)return 1;
    ll r = modpow(x, y / 2, m);
    r = (r * r) % m;
    if (y & 1)r = (r * x) % m;
    return r;
}

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

    bool merge(int i, int j) {
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

const ll MOD = 1e9+7;

const int mxN = 3e4+3;

int toint(string b) {
    int n = 0;
    for (char c : b) {
        n <<= 1;
        n += (c - '0');
    }
    return n;
}

void testCase() {
    ll l, m, q;
    cin >> l >> m >> q;

    vector<string> op(m);
    vll wt(m);

    for (int i = 0; i < m; ++i)cin >> op[i] >> wt[i];

    auto neis = [&] (int u) {
        vector<ii> ret;
        for (int i = 0; i < m; ++i) {
            int v = 0;
            for (int j = 0; j < l; ++j) {
                char curr = op[i][l-j-1];

                int bt = ((u & (1<<j))>0);
                if (curr == 'N') {
                } else if (curr == 'F') {
                    bt = 1 - bt;
                } else if (curr == 'S') {
                    bt = 1;
                } else {
                    bt = 0;
                }
                v |= (bt << j);
            }
            ret.push_back({v, wt[i]});
        }
        return ret;
    };

    while (q-->0) {
        string s, t;
        cin >> s >> t;

        int start = toint(s);
        int goal = toint(t);

        unordered_map<int,int> dst;
        dst[start] = 0;
        priority_queue<ii,vector<ii>, greater<ii>> pq;
        pq.push({0,start});

        bool f = 0;

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (dst[u] < d)continue;
            if (u == goal) {
                cout << d << " ";
                f = 1;
                break;
            }

            for (auto [v, w] : neis(u)) {
                if (!dst.count(v) || dst[v] > d+w) {
                    dst[v] = d+w;
                    pq.push({d+w,v});
                }
            }
        }
        if (f)continue;
        cout << "NP ";
    }
    cout << endl;
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
    }
    return 0;
}
