#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<int>;
template<typename t, size_t N>
using ar = array<t, N>;
using ii = ar<ll, 2>;
using vii = vector<ii>;
using vll = vector<ll>;

template<typename t>
istream& operator>>(istream& in, vector<t>& vec) {
    for (t& x : vec) {
        in >> x;
    }
    return in;
}

template<typename t>
ostream& operator<<(ostream& os, vector<t>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        os << vec[i];
        if (i < vec.size() - 1) os << " ";
    }
    return os;
}
#define all(v) begin(v), end(v)

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
    return (uint64_t)rng() % B;
}

template<typename t>
t min(const vector<t>& v) {
    return *min_element(all(v));
}

template<typename t>
t max(const vector<t>& v) {
    return *max_element(all(v));
}
const int INF = numeric_limits<int>::max();
const ll INFLL = numeric_limits<ll>::max();
const int mxN = (1e4+6)*16;
const ll MOD  = 1e9+7;

int n;
int k;
int st[mxN<<4];
int a[mxN];
int b[mxN];
int dp[mxN];
int pn[mxN];
vi idx[mxN];

void build(int p, int l, int r) {
    if (l == r) {
        pn[l] = p;
        return;
    }
    int mid = (l+r)>>1;
    build(p<<1, l, mid);
    build(p<<1|1,mid+1,r);
}

int query(int p, int l, int r, int i, int j) {
    if (l > r) return -INF;
    if (j < l || r < i) return -INF;
    if (i <= l && r <= j) return st[p];
    int mid = (l+r)>>1;

    if (mid < i)return query(p<<1|1, 1+mid, r, i, j);
    if (mid+1>j)return query(p<<1, l, mid, i, j);

    return max(query(p<<1, l, mid, i, j),
               query(p<<1|1, 1+mid, r, i, j));
}

void testCase() {
    scanf("%d%d",&n,&k);

    for (int i = 0; i < n * k; ++i) {
        scanf("%d", &a[i]);
        idx[a[i]].push_back(i);
    }
    
    for (int i = 0; i < n * k; ++i) {
        scanf("%d", &b[i]);
    }

    build(1,0,n*k-1);

    int ans = 0;
    for (int i = 0; i < n * k; ++i) {
        for (int z = k - 1; z >= 0; --z) {
            int j = idx[b[i]][z];
            int cur = dp[j];
            int dia = 1 + (j > 0 ? query(1, 0, n * k - 1, 0, j - 1) : 0);
            int nxt = max(cur,dia);
            ans = max(ans,nxt);
            dp[j] = nxt;
            int p = pn[j];
            st[p] = nxt;
            while (p>>1) {
                p >>= 1;
                st[p] = max(st[p<<1],st[p<<1|1]);
            }
        }
    }
    printf("%d\n",ans);
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
