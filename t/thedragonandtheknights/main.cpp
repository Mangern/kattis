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

void testCase() {
    ll n, m;
    cin >> n >> m;

    using line = array<ll,3>;
    vector<line> lines(n);

    ll tot = n+1;
    for (int i = 0; i < n; ++i) {
        cin >> lines[i][0] >> lines[i][1] >> lines[i][2];
        if (lines[i][0] == 0 && lines[i][1] == 0)continue;

        for (int j = 0; j < i; ++j) {
            if (lines[j][0] == 0 && lines[j][1] == 0)continue;
            tot += !(lines[i][0] * lines[j][1] == lines[i][1] * lines[j][0]);
        }
    }

    set<string> has;
    for (int i = 0; i < m; ++i) {
        string curr = "";
        ll x, y;
        cin >> x >> y;
        for (int j = 0; j < n; ++j) {
            ii p1, p2;

            if (lines[j][0] == 0 && lines[j][1] == 0)continue;

            if (lines[j][1] == 0) {
                if (lines[j][0] < 0) {
                    curr.push_back((lines[j][0] * x > -lines[j][2]) ? 'L' : 'R');
                } else {
                    curr.push_back((lines[j][0] * x < -lines[j][2]) ? 'L' : 'R');
                }
            } else if (lines[j][1] < 0) {
                curr.push_back((-lines[j][0] * x > y * lines[j][1] + lines[j][2] )? 'L' : 'R');
            } else {
                curr.push_back((-lines[j][0] * x < y * lines[j][1] + lines[j][2])?'L':'R');
            }
        }
        //cout << curr << endl;
        has.insert(curr);
    }

    assert(has.size() <= tot);
    cout << (has.size() == tot ? "PROTECTED" : "VULNERABLE") << endl;
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
