#pragma GCC optimize ("O3", "unroll-loops")
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
const int mxN = 502;

int n;
vll a;

bool vis[mxN];
bool hs_s[mxN];
bool hs_c[mxN][mxN];
bool hs_m[mxN][mxN][mxN];
ll dp_solve[mxN];
ll dp_check[mxN][mxN];
ll dp_merge[mxN][mxN][mxN];

ll merge(int l, int r, int mxi) {
    if (hs_m[l][r][mxi])return dp_merge[l][r][mxi];
    ll curr = r - l + 1;

    ll minl = a[l];
    for (int i= l; i <= mxi; ++i)minl = min(minl,a[i]);
    ll minr = a[r];
    for (int i = mxi+1; i <= r; ++i)minr = min(minr,a[i]);

    if (minl < minr) {
        for (int i = l; i <= mxi; ++i)curr -= (a[i] < minr);
    } else {
        for (int i = mxi+1; i <= r; ++i)curr -= (a[i] < minl);
    }
    hs_m[l][r][mxi] = 1;
    dp_merge[l][r][mxi] = curr;
    return curr;
}

// a[l..r] should be distinct 
ll check(int l, int r) {
    if (l >= r)return 0;
    if (hs_c[l][r])return dp_check[l][r];

    ll ret = INFLL;

    ll mini = l;
    ll minv = a[l];

    priority_queue<ll> pq;
    for (int i = l; i <= r; ++i) {
        pq.push(a[i]);
        if (a[i] < minv) {
            minv = a[i];
            mini = i;
        }
    }

    for (int mxi = l; mxi < mini; ++mxi) {
        while (pq.top() >= a[mxi])pq.pop();

        ll curr = check(l,mxi)+check(mxi+1,r);
        curr += r - l + 1;
        curr -= pq.size();
        ret = min(ret,curr);
    }

    pq = priority_queue<ll>();

    for (int i=l; i <= r; ++i) {
        pq.push(a[i]);
    }

    for (int mxi = r - 1; mxi >= mini; --mxi) {
        while (pq.top() >= a[mxi+1])pq.pop();
        ll curr = check(l,mxi)+check(mxi+1,r);
        curr += r - l + 1;
        curr -= pq.size();
        ret = min(ret,curr);
    }
    hs_c[l][r] = 1;
    dp_check[l][r] = ret;
    return ret;
}

ll solve(int l) {
    if (l >= n)return 0;
    //cout << "Solve: " << l << ".." << r << endl;
    if (hs_s[l])return dp_solve[l];

    vector<bool> vis(mxN, 0);
    ll ret = INFLL;

    ll cmx = 0;
    for (int i = l; i < n; ++i) {
        cmx = max(cmx,a[i]);
        if (vis[a[i]])break;
        vis[a[i]] = 1;
        
        if (cmx == i-l+1) {
            //cout << "Permutation: " << l << " to " << i << endl;
            ll x = solve(i+1);
            if (x != INFLL) {
                ret = min(ret, check(l,i)+x);
            }
        }
    }
    hs_s[l] = 1;
    dp_solve[l] = ret;
    return ret;
}


void testCase() {
    cin >> n;
    a = vll(n);
    cin >> a;

    ll ans = solve(0);
    if (ans == INFLL) {
        cout << "impossible" << endl;
    } else cout << ans << endl;
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
