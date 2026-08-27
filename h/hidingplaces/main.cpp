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
const int mxN = 8;

int dist[mxN*mxN][mxN*mxN];

int cti(int i,int j) {
    return i * mxN + j;
}

void testCase() {
    string s;
    cin >> s;
    int si = s[1]-'1';
    int sj = s[0]-'a';
    int st = cti(si,sj);

    int mx = 0;
    for (int i = 0; i < mxN*mxN; ++i)mx=max(mx,dist[st][i]);

    vii ans;
    for (int i = mxN-1; i >= 0; --i) {
        for (int j = 0; j < mxN; ++j) {
            if (dist[st][cti(i,j)] == mx) {
                ans.push_back({i,j});
            }
        }
    }
    cout << mx;
    for (auto [i,j] : ans) {
        char c = 'a';
        c += j;
        char d = '1';
        d += i;
        cout << " " << c << d;
    }
    cout << endl;
}

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {
    for (int i = 0; i < mxN*mxN; ++i) {
        for (int j = 0; j < mxN*mxN; ++j)dist[i][j] = INF;
    }
    for (int i = 0; i < mxN*mxN; ++i)dist[i][i] = 0;

    for (int i = 0; i < mxN; ++i) {
        for (int j = 0; j < mxN; ++j) {
            for (auto [ni,nj] : vector<ar<int,2>>{{i+1,j+2},{i-1,j+2},{i+1,j-2},{i-1,j-2},{i+2,j+1},{i-2,j+1},{i+2,j-1},{i-2,j-1}}) {
                if (ni < 0 || ni >= mxN || nj < 0 || nj >= mxN)continue;
                dist[cti(i,j)][cti(ni,nj)] = 1;
            }
        }
    }

    for (int k = 0; k < mxN*mxN; ++k) {
        for (int i = 0; i < mxN*mxN; ++i) {
            for (int j = 0; j < mxN * mxN; ++j) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                }
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
