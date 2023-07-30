// "Det enkle er ofte det beste"
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
const int mxN = 3e4+3;

void testCase() {
    int n;
    cin >> n;

    vi a(n);
    cin >> a;

    vii ans;
    for (int i = 0; i < n; ++i) {
        // find index of i+1
        int idx;
        for (idx =i; idx < n; ++idx)if (a[idx]==i+1)break;

        while (idx > i) {
            int sz = idx - i + 1;
            if (sz & 1)--sz;

            // choose: [idx - sz + 1, idx]
            ans.push_back({idx-sz+2,idx+1});

            for (int j = 0; j < sz/2; ++j) {
                swap(a[idx-j],a[idx-sz/2-j]);
            }
            idx = idx - sz/2;
            assert(a[idx] == i+1);
        }
    }
    cout << ans.size() << endl;
    for (auto pp : ans)cout << pp[0] << " " << pp[1] << endl;
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
