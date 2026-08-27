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

void testCase() {
    int n, d;
    cin >> n >> d;

    vector<bool> inf(n,0);
    int c;
    cin >> c;
    for (int i = 0; i < c; ++i) {
        int x;
        cin >> x, --x;
        inf[x] = 1;
    }

    vector<ar<ll,3>> enter;
    vii ints;
    for (int i = 0; i < n; ++i) {
        ll s, t;
        cin >> s >> t;

        if (inf[i]) {
            ints.push_back({s,t});
        } else {
            enter.push_back({s,t,i});
        }
    }

    sort(all(enter));

    while (d-->0 && ints.size()) {
        int k = enter.size();
        sort(all(ints));
        vii nints(1,ints[0]);
        for (int i = 1; i < ints.size(); ++i) {
            if (ints[i][0] <= nints.back()[1]) {
                nints.back()[1] = ints[i][1];
            } else {
                nints.push_back(ints[i]);
            }
        }
        ints = vii();
        int m = nints.size();
        //for (auto pp : nints) {
        //    cout << "inf: " << pp[0] << " " << pp[1] << endl;
        //}
        int j = 0;
        vector<ar<ll,3>> nenter;
        for (int i = 0; i < k; ++i) {
            //cout << "check: " << enter[i][0] << " " << enter[i][1] << endl;
            while (j < m && nints[j][1] < enter[i][0]) {
                ++j;
            }
            if (j < m && enter[i][1] >= nints[j][0]) {
                //cout << "inside inf: " << nints[j][0] << " " << nints[j][1] << endl;
                inf[enter[i][2]] = 1;
                ints.push_back({enter[i][0], enter[i][1]});
            } else {
                //cout << "not inside inf" << endl;
                nenter.push_back(enter[i]);
            }
        }
        swap(enter,nenter);
    }

    for (int i = 0; i < n; ++i) if (inf[i])cout << i+1 << " "; 
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
    //cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        testCase();
    }
    return 0;
}
