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
const int mxN = 2e5+7;

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}


int main() {
    setIO();
    pre();

    ll n, k;
    cin >> n >> k;


    ll ans = 0;
    while (n > k) {
        ll sz = k+1;
        ll per_block = 1;
        ll end1 = 1;

        while (sz * k < n && end1 < k) {
            sz = sz * k + 1;
            per_block = k * per_block + 1;
            end1 += 1;
        }

        if (end1 == k) {
            ans += per_block;
            n -= sz;
            ans += n;
            break;
        }

        if (sz * k == n) {
            ans += k * per_block;
            break;
        }

        ll a = n / sz;
        ans += a * per_block;
        n -= a * sz;
    }
    cout << ans << endl;
    
    
    return 0;
}
