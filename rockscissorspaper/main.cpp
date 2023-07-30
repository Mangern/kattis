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

bool beats(char a, char b) {
    if (a == b)return 0;
    if (a == 'R')return b == 'S';
    if (a == 'P')return b == 'R';
    return b == 'P';
}

void testCase() {
    int n, r, c;
    cin >> r >> c >> n;

    vector<string> a(r);
    for (auto& s : a)cin >> s;


    for (int k = 0; k < n; ++k) {
        vector<string> b(all(a));

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                for (auto [ni,nj] : vector<ii>{{i-1,j},{i+1,j},{i,j-1},{i,j+1}}) {
                    if (ni < 0 || ni >= r || nj < 0 || nj >= c)continue;
                    if (beats(a[i][j],a[ni][nj])) {
                        b[ni][nj] = a[i][j];
                    }
                }
            }
        }
        swap(a,b);
    }
    for (auto s : a)cout << s << endl;
    cout << endl;
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
