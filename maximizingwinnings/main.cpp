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
const int mxN = 2e5+6;
const ll MOD  = 1e9+7;

void testCase() {
    int n;
    cin >> n;
    if (!n)exit(0);

    vector<vll> a(n, vll(n, 0));

    for (int i = 0; i < n; ++i) for (int j = 0; j < n; ++j) {
        cin >> a[i][j];
    }

    int m;
    cin >> m;

    vll maxi(n, -INF); // max score ending at room i
    maxi[0] = 0;
    vll mini(n, INF); // min score ending at room i
    mini[0] = 0;

    for (int k = 0; k < m; ++k) {
        vll nmaxi(n, -INF);
        vll nmini(n, INF);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                nmaxi[j] = max(nmaxi[j], maxi[i] + a[i][j]);
                nmini[j] = min(nmini[j], mini[i] + a[i][j]);
            }
        }
        maxi = nmaxi;
        mini = nmini;
    }
    cout << max(maxi) << " " << min(mini) << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();
    int t = 50;
    //cin >> *t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
