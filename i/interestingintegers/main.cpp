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

ll exgcd(ll a, ll b, ll& x, ll& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    ll x1, y1;
    ll g = exgcd(b,a%b,x1,y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return g;
}

ll inv(ll a, ll f) {
    a = (a%f+f)%f;
    ll x,y;
    exgcd(a,f, x,y);

    x = (x%f+f)%f;
    return x;
}


void testCase() {
    ll n;
    cin >> n;

    ll F1 = 1;
    ll F2 = 2;

    ll a = n/2;
    ll b = (n+1)/2;

    while (F1+F2 <= n) {
        // solve F1*x+F2*y == n
        ll r = n;
        r %= F2;
        // F1*x == r mod F2
        ll i = inv(F1,F2);
        ll x0 = ((r * i)%F2+F2)%F2;

        // x0 = inv(F1) * r mod F2
        // x = F2 * k + x0
        // y = (n - F1*F2*k-F1*x0) / F2
        //
        // largest k s.t.
        // 
        // (n - F1*F2*k - F1*x0)/F2 > F2*k+x0
        //
        // F2*F2*k + F2*x0 < n - F1*F2*k-F1*x0
        // F2 (F1+F2) * k < n - (F1+F2)x0
        // k < (n-(F1+F2)*x0) / (F2*(F1+F2))

        ll k = (n - (F1+F2)*x0) / (F2*(F1+F2));

        ll x = F2*k+x0;

        ll y = (n - F1*x)/F2;

        
        /*
        if (F1*985+F2*1971 == n) {
            cout << F1 << " " << F2 << endl;
            cout << x << " " << y << endl;
        }
        */
        

        if (x > 0 && y >= x) {

            if (y < b || (y == b && x < a)) {
                a = x;
                b = y;
            }
        }

        /*
        r = n;
        r %= F1;
        i = inv(F2,F1);
        y = ((r * i)%F1+F1)%F1;
        x = (n - F2 * x)/F1;

        if (F1*985+F2*1971 == n) {
            cout << F1 << " " << F2 << endl;
            cout << x << " " << y << endl;
        }

        if (x > 0 && y >= x) {
            if (y < b || (y == b && x < a)) {
                a = x;
                b = y;
            }
        }
        */


        ll tmp = F1+F2;
        F1 = F2;
        F2 = tmp;
    }
    cout << a << " " << b << endl;
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
