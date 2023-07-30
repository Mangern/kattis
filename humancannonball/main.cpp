#include <bits/stdc++.h>
#include <cmath>
#include <limits>
#include <queue>
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

double euclid(double x1, double y1, double x2, double y2) {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double euclid(ar<double,2> p1, ar<double,2> p2) {
    return euclid(p1[0],p1[1],p2[0],p2[1]);
}

void testCase() {
    double sx,sy,ex,ey;
    cin >> sx >> sy >> ex >> ey;
    int n;
    cin >> n;

    vector<ar<double,2>> pts(n+2);
    for (int i = 1; i <= n; ++i) {
        cin >> pts[i][0] >> pts[i][1];
    }
    pts[0] = {sx,sy};
    pts[n+1] = {ex,ey};


    priority_queue<pair<double,int>, vector<pair<double,int>>, greater<pair<double,int>>> pq;
    pq.push({0.0,0});
    vector<double> dist(n+2);
    dist[0] = 0.0;
    for (int i = 1; i <= n+1; ++i) {
        dist[i] = numeric_limits<double>::infinity();
    }

    while (pq.size()) {
        auto [d,i] = pq.top();
        pq.pop();
        if (dist[i] < d)continue;
        if (i == n+1)continue;
        if (i == 0) {
            for (int j = 1; j <= n+1; ++j) {
                double nd = euclid(pts[i],pts[j]);
                if (dist[j] > dist[i] + nd / 5) {
                    dist[j] = dist[i] + nd / 5;
                    pq.push({dist[j],j});
                }
            }
        } else {
            for (int j = 1; j <= n+1; ++j) {
                double nd = euclid(pts[i],pts[j]);
                if (nd >= 50) {
                    nd = (nd - 50)/5 + 2;
                } else {
                    nd = min(2 + (50-nd)/5, nd);
                }
                if (dist[j] > dist[i] + nd) {
                    dist[j] = dist[i]+nd;
                    pq.push({dist[j], j});
                }
            }
        }
    }
    cout << dist[n+1] << endl;
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

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
