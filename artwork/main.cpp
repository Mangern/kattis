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
struct UnionFind {
    int num_sets;
    vi p, sz, rnk;
    UnionFind(int n) {
        num_sets = n;
        p = vi(n);
        iota(all(p),0);
        rnk = vi(n,0);
        sz = vi(n,1);
    }

    int find(int i) {
        if (p[i] == i)return i;
        return p[i] = find(p[i]);
    }

    bool check(int i, int j) {
        return find(i)==find(j);
    }

    bool join(int i, int j) {
        i = find(i);
        j = find(j);
        if (i == j)return 0;
        if (rnk[i] < rnk[j]) {
            sz[j] += sz[i];
            p[i] = j;
        } else {
            sz[i] += sz[j];
            p[j] = i;
            if (rnk[i] == rnk[j]) {
                ++rnk[i];
            }
        }
        --num_sets;
        return 1;
    }
};
const int mxN = 3e4+3;
int n,m,q;

int cti(int i, int j) {
    return j * n + i;
}

void testCase() {
    cin >> n >> m >> q;

    UnionFind uf(n*m);
    vector<ar<int,4>> qrs(q);
    for (int i = 0; i < q; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> qrs[i][j];
            --qrs[i][j];
        }
    }

    vi col(n*m, 0);
    int nblack = 0;

    for (int i = 0; i < q; ++i) {
        int x = qrs[i][0];
        int y = qrs[i][1];

        while (true) {
            if (++col[cti(x,y)] == 1)++nblack;
            if (x != qrs[i][2])++x;
            else if (y != qrs[i][3])++y;
            else break;
        }
    }

    for (int x = 0; x < n; ++x) for (int y = 0; y < m; ++y) {
        if (col[cti(x,y)])continue;
        if (x > 0 && !col[cti(x-1,y)])uf.join(cti(x,y),cti(x-1,y));
        if (y > 0 && !col[cti(x,y-1)])uf.join(cti(x,y),cti(x,y-1));
    }

    vi ans;
    for (int i = q - 1; i >= 0; --i) {
        ans.push_back(uf.num_sets - nblack);

        int x = qrs[i][2];
        int y = qrs[i][3];

        while (true) {
            if (!--col[cti(x,y)]) {
                for (auto [nx,ny] : vector<ii>{{x-1,y}, {x+1,y}, {x,y-1}, {x,y+1}}) {
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !col[cti(nx,ny)]) {
                        uf.join(cti(x,y),cti(nx,ny));
                    }
                }
                --nblack;
            }
            if (x != qrs[i][0])--x;
            else if (y != qrs[i][1])--y;
            else break;
        }
    }
    while (ans.size()) {
        cout << ans.back() << endl;
        ans.pop_back();
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
