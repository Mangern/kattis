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

bool vis[4][4];

void testCase() {
    int n;
    cin >> n;
    vector<string> dict(n);
    cin >> dict;

    sort(all(dict));

    int b;
    cin >> b;
    int k = 4;

    auto get_score = [&] (const string& s) {
        int l = s.length();
        if (l < 3)return 0;
        if (l <= 4)return 1;
        if (l == 5)return 2;
        if (l == 6)return 3;
        if (l == 7)return 5;
        return 11;
    };

    auto check = [&] (int idx, vector<string> board) {
        string curr = dict[idx];
        //cout << "Check " << curr << "!" << endl;

        function<bool(int,int,int)> dfs = [&] (int i, int j, int at) {
            if (at == curr.length() - 1)return true;

            for (int di = -1; di <= 1; ++di) for (int dj = -1; dj <= 1; ++dj) if (di != 0 || dj != 0) {
                if (i+di < 0 || i+di >= 4 || j+dj < 0 || j+dj >= 4 || vis[i+di][j+dj] || board[i+di][j+dj] != curr[at+1])continue;
                vis[i+di][j+dj] = 1;
                if (dfs(i+di,j+dj,at+1))return true;
                vis[i+di][j+dj] = 0;
            }
            return false;
        };

        for (int a = 0; a < 4; ++a)for (int b = 0; b < 4; ++b)vis[a][b] = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) if (board[i][j] == curr[0]) {
                vis[i][j] = 1;
                if (dfs(i,j,0))return true;
                vis[i][j] = 0;
            }
        }
        return false;
    };

    while (b-->0) {
        vector<string> board(k);
        cin >> board;

        int mx_len = 0;
        string mx_w;
        int score = 0;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (check(i,board)) {
                score += get_score(dict[i]);
                ++cnt;
                if (dict[i].length() > mx_len) {
                    mx_len = dict[i].length();
                    mx_w = dict[i];
                }
            }
        }
        cout << score << " " << mx_w << " " << cnt << endl;
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
