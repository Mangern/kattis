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
    string line;

    multiset<int> above, below;

    while (getline(cin,line)) {
        if (line == "")continue;
        if (line == "#") {
            cout << *above.begin() << endl;
            above.erase(above.begin());
            if (above.size() < below.size()) {
                above.insert(*--below.end());
                below.erase(--below.end());
            }
        } else {
            int x = stoi(line);
            if (above.empty())above.insert(x);
            else {
                if (x >= *above.begin()) {
                    above.insert(x);
                } else {
                    below.insert(x);
                }

                if (below.size() > above.size()) {
                    above.insert(*--below.end());
                    below.erase(--below.end());
                } else if (above.size() - below.size() >= 2) {
                    below.insert(*above.begin());
                    above.erase(above.begin());
                }
            }
        }
    }
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
