#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
template<typename t, size_t N>
using ar = array<t,N>;
using ii = ar<ll,2>;
using vii = vector<ii>;

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
const int mxN = 3e4+3;

void testCase(int test) {
    int n;
    cin >> n;

    map<ll,ll> out;
    vector<vll> adr(n, vll());

    for (int i = 0; i < n; ++i) {
        int m;
        cin >> m;

        adr[i] = vll(m);
        cin >> adr[i];
    }
    vi in(n,0);
    vector<vi> adj(n, vi());

    for (int i = 0; i < n; ++i) {

        set<ll> seen;
        for (int k = 0; k < adr[i].size() - 1; ++k) {
            auto j = adr[i][k];
            if (out.count(j) && !seen.count(j)) {
                adj[out[j]].push_back(i);
                ++in[i];
                seen.insert(j);
            }
        }

        out[adr[i].back()] = i;
    }


    int ans = 0;
    vi open_st;
    for (int i = 0; i < n; ++i) if (!in[i])open_st.push_back(i);

    while (!open_st.empty()) {
        ++ans;

        vi new_st;
        for (int i : open_st)for (int j : adj[i])if (--in[j] == 0)new_st.push_back(j);
        swap(open_st, new_st);
    }
    cout << test << " " << ans << endl;
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
        testCase(tc);
    }
    return 0;
}
