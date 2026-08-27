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
const int mxN = 61;

bool is_prime[1000];

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

vll primes;

void pre() {
    memset(is_prime, 1, sizeof is_prime);

    for (int i = 2; i < 1000 && primes.size() < 59; ++i) {
        if (is_prime[i])primes.push_back((ll)i);
        for (int j = i * i; j < 1000; j += i)is_prime[j] = false;
    }
}

int n;

vi adj[mxN];
vi tree[mxN];
ll ans[mxN];
int nxt[mxN];



int pptr = 0;
ll next() {
    return primes[pptr++];
}

int dfs_path(int u, int cf = -1) {
    int mx = -1;
    for (int v : adj[u])if (v != cf) {
        int res = dfs_path(v, u);
        if (res > mx) {
            mx = res;
            nxt[u] = v;
        }
    }
    if (mx == -1) {
        mx = 0;
        nxt[u] = -1;
    }

    if (ans[u] == -1)++mx;
    return mx;
}

int main() {
    setIO();
    pre();

    memset(ans, -1, sizeof ans);


    cin >> n;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v, --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans[0] = 1;

    while (true) {
        int u = 0;
        if (!dfs_path(0))break;
        ll p = next();

        ll prev = ans[u];
        while (ans[u] != -1) {
            prev = ans[u];
            u = nxt[u];
        }

        prev *= p;
        while (u != -1) {
            ans[u] = prev;
            prev *= p;
            u = nxt[u];
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << endl;
}

