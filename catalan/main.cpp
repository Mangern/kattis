#pragma GCC optimize ("O3")
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
const int mxN = 5000*2 + 5;
const ll M = 10000000;

struct MEGA_INT {
    vll chunks;

    MEGA_INT(ll val) {
        assert(val < M);
        chunks = vll(350,0);
        chunks[0] = 1;
    }


    void mul(ll x) {
        vll a(chunks.size());
        vll b(chunks.size());
        ll r = 0;
        for (ll i = 0; i < chunks.size(); ++i) {
            chunks[i] *= x;
            ll d = chunks[i] / M;
            chunks[i] %= M;
            chunks[i] += (r%M);
            d += chunks[i] / M;
            chunks[i] %= M;
            r /= M;
            r += d;
        }

    }

    void print() {
        ll i = chunks.size() - 1;
        while (!chunks[--i]){};
        for (; i >= 0; --i) {
            cout << chunks[i];
        }
        cout << endl;
    }
};


ll spf[mxN];


void testCase() {


    ll n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    }

    vll cnt(2*n+2, 0);
    for (ll i = 2; i <= n+1; ++i) {
        ll x = i;
        while (x > 1) {
            ++cnt[spf[x]];
            x /= spf[x];
        }
    }

    vll xs;
    for (ll i = n+1; i <= 2*n; ++i) {
        ll x = i;
        while (x > 1) {
            if (cnt[spf[x]]) {
                --cnt[spf[x]];
            } else {
                xs.push_back(spf[x]);
            }
            x /= spf[x];
        }
    }

    vll ys(1,xs[0]);
    for (ll i = 1; i < xs.size(); ++i) {
        if (ys.back()*xs[i] < M)ys.back()*=xs[i];
        else ys.push_back(xs[i]);
    }

    MEGA_INT ans(1);
    for (auto p : ys)ans.mul(p);
    ans.print();
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
    spf[0] = 0;
    spf[1] = 1;
    memset(spf,0,sizeof spf);
    for (ll i = 2; i < mxN; ++i) {
        if (spf[i])continue;
        spf[i] = i;
        for (ll j = i * i; j < mxN; j += i) if (!spf[j]) {
            spf[j] = i;
        }
    }

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
