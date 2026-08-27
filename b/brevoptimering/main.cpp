#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = pair<ll,ld>;
using vii = vector<ii>;

#define all(v) begin(v), end(v)

const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();
const ld INFLD = numeric_limits<ld>::infinity();

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
const int mxN = 3e4+3;

void testCase() {
    int n;
    cin >> n;

    vector<ld> M(n);
    vector<vii> adj(n, vii());
    vector<ld> rec(n, 0.0);
    vi in(n,0);

    for (int i = 0; i < n; ++i) {
        cin >> M[i];

        int k;
        cin >> k;
        adj[i] = vii(k);
        for (auto& pp : adj[i]) {
            cin >> pp.first >> pp.second;
            --pp.first;
            ++in[pp.first];
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i)if (in[i] == 0) {
        rec[i] = INFLD;
        q.push(i);
    }

    vi ans;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        ld U = min(M[u], rec[u]);
        if (abs(U-M[u]) <= 0.0001)ans.push_back(u+1);

        for (auto [v, perc] : adj[u]) {
            rec[v] += (perc/100)*U;
            if (!--in[v])q.push(v);
        }
    }
    sort(all(ans));
    cout << ans << endl;
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
