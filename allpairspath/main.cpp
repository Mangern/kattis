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
    ll n,m,q;
    cin >> n >> m >> q;
    if (!n)return false;

    vector<vll> dist(n, vll(n,INFLL));

    for (int i = 0; i < m; ++i) {
        ll u,v,w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
    }

    for (int i = 0; i < n; ++i)dist[i][i] = 0;

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INFLL && dist[k][j] != INFLL) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }

    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (dist[i][k] != INFLL && dist[k][j] != INFLL) {
                    if (dist[i][k] == -INFLL || dist[k][j] == -INFLL || dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = -INFLL;
                    }
                }
            }
        }
    }


    while (q-->0) {
        int u,v;
        cin >> u >> v;

        if (dist[u][v] == INFLL) {
            cout << "Impossible" << endl;
        } else if (dist[u][v] == -INFLL) {
            cout << "-Infinity" << endl;
        } else {
            cout << dist[u][v] << endl;
        }
    }
    cout << endl;

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

    while (testCase()){}

    return 0;
}
