#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using ull = uint64_t;

static int C;

template<int M, class B>
struct A {
	int x; B b; A(int x=0) : x(x), b(x) {}
	A(int x, B b) : x(x), b(b) {}
	A operator+(A o){int y = x+o.x; return{y - (y>=M)*M, b+o.b};}
	A operator-(A o){int y = x-o.x; return{y + (y< 0)*M, b-o.b};}
	A operator*(A o) { return {(int)(1LL*x*o.x % M), b*o.b}; }
	explicit operator ull() const { return x ^ (ull) b << 21; }
	bool operator==(A o) const { return (ull)*this == (ull)o; }
	bool operator<(A o) const { return (ull)*this < (ull)o; }
};
typedef A<1000000007, A<1000000009, unsigned>> H;

static const H MOD = 1e9+7;
H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

string normalize(string line) {
    string result;

    while (!line.empty() && isspace(line.back()))line.pop_back();

    int i;
    for (i = 0; i < line.length() && isspace(line[i]); ++i);

    for (int j = i; j < line.length(); ++j) {
        char c = line[j];
        if (result.empty() || 
          !(isspace(result.back()) && isspace(c)))
            result.push_back(c);
    }

    return result;
}

#include <sys/time.h>
int main() {
    {
        timeval tp;
	    gettimeofday(&tp, 0);
	    C = (int)tp.tv_usec; // (less than modulo)
    }
    string line;
    getline(cin, line);
    int n = stoi(line);
    vector<string> names;
    vector<vector<H>> repos;
    for (int i = 0; i < n; ++i) {
        getline(cin, line);
        names.push_back(normalize(line));
        auto& v = repos.emplace_back();

        for (;;) {
            getline(cin, line);
            string s = normalize(line);
            if (s == "***END***") break;
            if (s.empty()) continue;
            v.push_back(hashString(s));
        }
    }

    vector<H> query;
    for (;;) {
        getline(cin, line);
        string s = normalize(line);
        if (s == "***END***") break;
        if (s.empty()) continue;
        query.push_back(hashString(s));
    }

    vector<string> ans;
    int ans_len = 0;
    for (int idx = 0; idx < n; ++idx) {
        int r = query.size();
        const auto& t = repos[idx];
        int m = t.size();
        vector<vector<int>> dp(r, vector<int>(m, 0));
        int cur = 0;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < m; ++j) {
                if (query[i] == t[j]) {
                    if (i == 0 || j == 0)dp[i][j] = 1;
                    else {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    cur = max(cur, dp[i][j]);
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        if (cur > ans_len) {
            ans_len = cur;
            ans.clear();
        }
        if (cur == ans_len && cur > 0) {
            ans.push_back(names[idx]);
        }
    }
    cout << ans_len;
    for (auto s : ans)cout << ' ' << s;
    cout << endl;
}
