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
const int K = 501;

bool dp[K][K];

void testCase() {
    int n, m;
    cin >> n >> m;
    string st;
    cin >> st;

    bool flp = (st == "Vicky");

    if (flp) {
        swap(n,m);
    }
    cout << st << (dp[n][m] ? " can win" : " cannot win") << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
    auto check = [&] (int w, int h) {
        for (int i = 1; i < h; ++i) {
            if (!dp[i][w] && !dp[h-i][w])return true;
        }
        return false;
    };
    
    for (int i = 1; i < K; ++i) {
        for (int j = i; j < K; ++j) {
            // consider
            int w = i;
            int h = j;

            dp[w][h] = check(w,h);

            if (i != j) {
                h = i;
                w = j;

                dp[w][h] = check(w,h);
            }
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
