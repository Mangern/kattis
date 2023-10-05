#include <bits/stdc++.h>
#include <math.h>
#include <random>
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

template<typename t>
t min(const vector<t>& vec) {
    t ans = vec[0];
    for (const auto& el : vec) {
        ans = min(ans, el);
    }
    return ans;
}

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
    int n;
    cin >> n;

    vector<ar<double,3>> circ(n);
    for (auto& c : circ)cin >> c[0] >> c[1] >> c[2];

    int NUM_SAMPLE = 1000000;

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(-10.0, 20.0);

    int num_inside = 0;
    for (int i = 0; i < NUM_SAMPLE; ++i) {
        double x = dis(gen);
        double y = dis(gen);

        for (auto [cx, cy, r] : circ) {
            if ((cx -x)*(cx-x) + (cy-y)*(cy-y) <= r * r) {
                ++num_inside;
                break;
            }
        }
    }

    cout << 30 * 30 * ((double)num_inside) / ((double)(NUM_SAMPLE)) << endl;

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
