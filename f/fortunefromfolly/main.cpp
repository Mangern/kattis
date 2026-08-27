#include <bits/stdc++.h>
#include <iomanip>
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

template<typename T>
vector<T> gauss(vector<vector<T>>& A) {
    int n = A.size();

    for (int j = 0; j < n - 1; ++j) {
        for (int i = j+1; i < n; ++i) {
            T t = A[i][j] / A[j][j];
            for (int k = 0; k <= n; ++k) {
                A[i][k] -= A[j][k] * t;
            }
        }
    }

    vector<T> ans(n, 0.0);

    for (int i = n - 1; i >= 0; --i) {
        T s = 0;
        for (int j = i+1; j < n; ++j) {
            s += A[i][j] * ans[j];
        }
        ans[i] = (A[i][n] - s) / A[i][i];
    }
    return ans;
}

void testCase() {
    int n, k;
    double p;
    cin >> n >> k >> p;

    int N = (1<<n);

    vector<vector<double>> mat(N, vector<double>(N+1, 0.0));


    for (int i = 0; i < N; ++i) {
        mat[i][i] += 1.0;


        if (__builtin_popcount(i) < k) {
            mat[i][N] += 1;
            int j = ((i << 1) | 1)%N;
            ////cout << i << " " << j << endl;
            mat[i][j] -= p;
            j = (i<<1)%N;
            mat[i][j] -= (1.0-p);
        }

    }
    //for (auto r : mat)cout << r << endl;
    //cout << endl;

    auto E = gauss(mat);
    cout << setprecision(8) << fixed << E[0] << endl;
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
