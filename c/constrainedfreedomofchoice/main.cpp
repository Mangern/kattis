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

bool testCase() {
    ll n, m;
    cin >> n >> m;
    if (!n && !m)return false;

    vector<string> board(n);
    cin >> board;


    vector<vll> dp(n, vll(2*m,0LL));
    dp[n-1][0] = 1;

    for (ll j = 0; j < 2*m - 1; ++j) {
        for (ll i = n - 1; i >= 0; --i) {
            if (j & 1) {
                if (board[i][(j/2)+1] == '.') {
                    dp[i][j+1] += dp[i][j];
                }
            } else {
                for (int k = i; k < n; ++k) {
                    if (board[k][j/2] == '.') {
                        dp[k][j+1] += dp[i][j];
                    } else break;
                }
                for (int k = i - 1; k >= 0; --k) {
                    if (board[k][j/2] == '.') {
                        dp[k][j+1] += dp[i][j];
                    } else break;
                }
            }
        }
    }
    //for (auto v : dp)cout << v << endl;
    cout << dp[0][2*m-1] << endl;
    return true;
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

    while (testCase()){}
    return 0;
}
