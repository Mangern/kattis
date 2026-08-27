// Make a vector more dynamic?
//  -> Range sum / point update on indexes
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

struct FenwickTree {
    vll a;
    ll n;
    FenwickTree(ll _n) {
        n = _n;
        a = vll(n+2,0);
    }

    void add(ll i, ll x) {
        ++i;
        for (; i <= n+1; i += (i & -i))a[i] += x;
    }

    ll query(ll i) {
        ++i;
        ll sm = 0;
        for (; i > 0; i -= (i & -i))sm += a[i];
        return sm;
    }
};

void testCase() {
    int n;
    cin >> n;

    vll idx(n);
    auto cmp = [&] (auto x, auto y) {
        return idx[x] < idx[y];
    };
    set<ll,decltype(cmp)> st(cmp);
    for (int i = 0; i < n; ++i) {
        ll x;
        cin >> x, --x;
        idx[x] = i;

        st.insert(x);
    }

    vll goal(n);
    cin >> goal;
    for (auto& x : goal)--x;

    FenwickTree ft(n);

    for (ll i = 0; i < n; ++i) {
        ll widx = idx[goal[i]] + ft.query(idx[goal[i]]);
        //cout << "Idx of " << goal[i]+1 << " = " << widx << endl;
        st.erase(goal[i]);
        if (widx == i)continue;

        if ((widx&1) != (i&1)) {
            if (i == n - 2) {
                cout << "Impossible" << endl;
                return;
            }

            ll i1 = *st.begin();
            st.erase(i1);
            ll i2 = *st.begin();
            st.erase(i2);

            swap(idx[i1], idx[i2]);
            st.insert(i1);
            st.insert(i2);
        }
        ft.add(0,1);
        ft.add(idx[goal[i]],-1);
    }
    cout << "Possible" << endl;
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
