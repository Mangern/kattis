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

ll H(ll n) {
    return (n<<2)+1;
}

ll deH(ll h) {
    return ((h - 1)>>2);
}

const ll mxN = 250001;

ll spf[mxN];
ll prf[mxN];

bool testCase() {
    ll h;
    cin >> h;
    if (!h)return false;

    cout << h << " ";
    cout << prf[deH(h)] << endl;

    return true;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
    spf[0] = 1;

    for (ll i = 1; i < mxN; ++i) {
        if (spf[i])continue;
        spf[i] = H(i);
        for (ll mul = i; H(mul) * H(i) < H(mxN); ++mul) {
            ll j = H(mul) * H(i);
            if (spf[deH(j)])spf[deH(j)] = min(spf[deH(j)], H(i));
            else spf[deH(j)] = H(i);
        }
    }
    
    prf[0] = 0;

    for (ll i = 1; i < mxN; ++i) {
        prf[i] = prf[i-1];
        if (spf[i] == H(i))continue;
        ll a = spf[i];
        ll b = H(i) / a;

        if ((a % 4 != 1) || (b % 4 != 1))continue;
        if (a * b != H(i))continue;
        if (spf[deH(a)] == a && spf[deH(b)] == b)++prf[i];
    }
}

int main() {
    setIO();
    pre();

    while (testCase()){};

    return 0;
}
