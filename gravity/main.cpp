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

    bool merge(int i, int j) {
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

ii read_pair() {
    string line;
    if (!getline(cin,line))return {-1,-1};
    int a = stoi(line.substr(0,line.find(" ")));
    int b = stoi(line.substr(line.find(" ") + 1, line.length()));
    return {a,b};
}

bool testCase() {
    auto [n,m] = read_pair();
    if (!n && !m)return false;

    vector<string> grid(n);
    for (auto& s : grid)getline(cin,s);


    auto cti = [&] (int i, int j) {
        return i * m + j;
    };

    vector<vi> at(n+1, vi(m));
    UnionFind uf(n*m+1);
    vi is_ground(n*m+1, 0);
    is_ground[n*m] = 1;
    for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) {
        at[i][j] = cti(i,j);
        if (i == n - 1 && grid[i][j] != ' ')is_ground[cti(i,j)] = 1;
    }


    auto join = [&] (int i, int j) {
        if (uf.check(i,j))return;
        bool any = is_ground[uf.find(i)] || is_ground[uf.find(j)];
        uf.merge(i,j);
        is_ground[uf.find(i)] = any;
        is_ground[uf.find(j)] = any;
    };


    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < m; ++j)if (grid[n-1][j] != ' ') {
            is_ground[uf.find(at[n-1][j])] = 1;
        }
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) if (grid[i][j] != ' ') {
                if (grid[i+1][j] != ' ') {
                    join(at[i+1][j], at[i][j]);
                }
                if (j > 0 && grid[i][j-1] != ' ') {
                    join(at[i][j-1], at[i][j]);
                }
            }
        }

        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j < m; ++j) if (grid[i][j] != ' ') {
                if (!is_ground[uf.find(at[i][j])]) {
                    at[i+1][j] = at[i][j];
                    at[i][j] = n * m; 
                    grid[i+1][j] = grid[i][j];
                    grid[i][j] = ' ';
                }
            }
        }
    }

    for (auto s : grid)cout << s << endl;
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
    int t = 1;
    //cin >> t;

    while (testCase()){}
    return 0;
}
