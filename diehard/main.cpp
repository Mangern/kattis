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
const int mxN = 2e5+7;

void setIO() {
    cin.tie(0)->sync_with_stdio(0);
}

void pre() {

}

int main() {
    setIO();
    pre();

    vector<vll> dice(3, vll(6));
    for (int i = 0; i < 3; ++i)cin >> dice[i];

    vi in(3, 0);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (j == i)continue;
            int iwin = 0;
            int jwin = 0;

            for (int a = 0; a < 6; ++a) {
                for (int b = 0; b < 6; ++b) {
                    if (dice[i][a] > dice[j][b])++iwin;
                    if (dice[i][a] < dice[j][b])++jwin;
                }
            }

            if (iwin > jwin) {
                ++in[j];
            }
            if (jwin > iwin) {
                ++in[i];
            }
        }
    }

    vi pos;
    for (int i = 0; i < 3; ++i) {
        if (!in[i]) {
            pos.push_back(i);
        }
    }

    if (pos.empty()) {
        cout << "No dice" << endl;
    } else if (pos.size() == 1) {
        cout << pos[0]+1 << endl;
    } else {
        vll a = dice[pos[0]];
        vll b = dice[pos[1]];
        
        if (a[5] > b[0]) {
            cout << pos[0]+1 << endl;
        } else {
            cout << "No dice" << endl;
        }
    }
}

