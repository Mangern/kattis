// A cool lesson on index compression
// for memory optimization of a prime sieve
//  - Watch the memory limit!
// 
// This program stores only primality data of numbers
// congruent to 1 or 5 mod 6, because all other remainders 
// are composite (except 2 and 3, handled separately)
//  - Reduces memory usage by a factor of 3
//
// Question: are there other, more optimal numbers?
// For example, doing the same with mod=24 would also yield
// 1/3 of the memory usage (8 coprime remainders of 24)
//
// Lesson: Problems consisting solely of a well-known technique probably have some 
// sort of "catch". However, a modification of the well-known algorithm works in many cases.
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
const int mxN = 33333339;

int cnt_primes = 2;
bool is_prime[mxN];

int index_of(int n) {
    int r = (n%6); 
    if (r != 1 && r != 5)return 0;
    return 2*(n/6)+(r==5);
}

void testCase() {
    int n,q;
    int x;
    cin >> n >> q;

    if (n == 1) {
        cout << 0 << endl;
        while (q-->0) {
            cin >> x;
            cout << 0 << endl;
        }
        return;
    }
    if (n <= 3) {
        cout << 2 - (n == 2) << endl;
        while (q-->0) {
            cin >> x;
            cout << (x>=2) << endl;
        }
        return;
    }

    for (int k = 1; k <= n; ++k) {
        cnt_primes += is_prime[index_of(k)];
    }

    cout << cnt_primes << endl;
    while (q-->0) {
        cin >> x;

        if (x <= 3) {
            cout << (x!=1) << endl;
            continue;
        }

        cout << is_prime[index_of(x)] << endl;
    }
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
    memset(is_prime, 1, sizeof is_prime);
    is_prime[0] = 0;

    const ll MX = 1e8+2;

    for (ll i = 5; i < MX; ++i) {
        if (!is_prime[index_of(i)])continue;
        for (ll j = i * i; j < MX; j += i) {
            is_prime[index_of(j)] = 0;
        }
    }
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
