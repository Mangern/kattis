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

bool testCase() {
    string input;
    //if (!getline(cin,input))return false;
    //ll c = stoll(input.substr(0, input.find(" ")));
    //ll n = stoll(input.substr(input.find(" "), input.length()));
    //

    ll c, n;
    cin >> c >> n;

    if (!c || !n)return false;



    vll v(n);
    vll w(n);
    for (int i = 0; i < n; ++i)cin >> v[i] >> w[i];

    for (int i = 0; i < n; ++i)if (!v[i] || !w[i])return false;

    vector<vll> dp(n+1, vll(c+1, 0));
    vector<vector<bool>> took(n+1, vector<bool>(c+1,0));
    vll mxdp(n+1, 0);

    for (int i =1; i <= n; ++i) {
        for (int j = 0; j <= c; ++j) {
            dp[i][j] = dp[i-1][j];
            if (j >= w[i-1]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i-1]]+v[i-1]);
                if (dp[i][j] > dp[i-1][j])took[i][j] = 1;
            }
        }
        mxdp[i] = max_element(all(dp[i])) - begin(dp[i]);
    }

    //for (auto v : dp)cout << v << endl;

    vll ans;
    int ptr = n;
    ll d_val = dp[n][mxdp[n]];
    int j = mxdp[n];
    while (ptr) {
        if (took[ptr][j]) {
            ans.push_back(ptr-1);
            d_val -= v[ptr-1];
            j -= w[ptr-1];
        }
        --ptr;
    }

    cout << ans.size() << endl;
    cout << ans << endl;
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

    while (cin.good())testCase();
    return 0;
}
