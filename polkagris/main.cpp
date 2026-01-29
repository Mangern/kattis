#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
 
#define rep(i, lo, hi) for(int i = (lo); i < (hi); ++i)
#define sz(v) (v).size()
 
typedef uint64_t ull;
struct H {
	ull x; H(ull x=0) : x(x) {}
	H operator+(H o) { return x + o.x + (x + o.x < x); }
	H operator-(H o) { return *this + ~o.x; }
	H operator*(H o) { auto m = (__uint128_t)x * o.x;
		return H((ull)m) + (ull)(m >> 64); }
	ull get() const { return x + !~x; }
	bool operator==(H o) const { return get() == o.get(); }
	bool operator<(H o) const { return get() < o.get(); }
};
static const H C = (ll)1e11+3; // (order ~ 3e9; random also ok)
 
struct HashInterval {
	vector<H> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,0,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};
 
vector<H> getHashes(string& str, int length) {
	if (sz(str) < length) return {};
	H h = 0, pw = 1;
	rep(i,0,length)
		h = h * C + str[i], pw = pw * C;
	vector<H> ret = {h};
	rep(i,length,sz(str)) {
		ret.push_back(h = h * C + str[i] - pw * str[i-length]);
	}
	return ret;
}
 
H hashString(string& s){H h{}; for(char c:s) h=h*C+c;return h;}

vi z(const string& s) {
    int n = s.size();
    vector<int> z(n);
    int x = 0, y = 0;
    for (int i = 1; i < n; i++) {
        z[i] = max(0,min(z[i-x],y-i+1));
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            x = i; y = i+z[i]; z[i]++;
        }
    }
    return z;
}

int main() {
    int n, m;
    cin >> n >> m;
    string s, pat;
    cin >> s >> pat;

    string r = s;
    reverse(begin(r), end(r));

    string rpat = pat;
    reverse(begin(rpat), end(rpat));

    vi cent(n);

    auto hsh = HashInterval(s);
    auto rsh = HashInterval(r);

    auto isp = [&] (int l, int r) {
        if (l < 0 || r >= n) return false;
        if (l > r) return false;
        auto cur = hsh.hashInterval(l, r + 1);

        auto rev = rsh.hashInterval(n - r - 1, n - l);
        return cur == rev;
    };

    for (int i = 0; i < n; ++i) {
        int lo = 0;
        int hi = n;

        while (lo < hi) {
            int mid = (lo + hi + 1) / 2;

            if (isp(i - mid, i + mid)) {
                lo = mid;
            } else {
                hi = mid - 1;
            }
        }
        cent[i] = lo;
    }

    vi lft(n, 0), rgt(n, 0);

    for (int i = 0; i < n-1; ++i) {
        rgt[i+1] = cent[i];
        lft[i] = cent[i+1];
    }

    vi lcut(n, 0), rcut(n, 0);
    int l1 = -1;
    for (int i = 0; i < n; ++i) {
        if (i - lft[i] <= l1) {
            lcut[i] = 1;
            l1 = i;
        }
    }
    int r1 = n;
    for (int i = n - 1; i >= 0; --i) {
        if (i + rgt[i] >= r1) {
            rcut[i] = 1;
            r1 = i;
        }
    }

    // for (int i : lcut) cout << i << " ";
    // cout << endl;
    // for (int i : rcut) cout << i << " ";
    // cout << endl;

    for (const string &p : vector<string>{pat, rpat}) {
        string search = p + "$" + s;
        vi zar = z(search);

        for (int i = m + 1; i < search.length(); ++i) {
            if (zar[i] == m) {
                int i1 = i - m - 2;
                int i2 = i1 + m + 1;

                if ((i1 < 0 || lcut[i1]) && (i2 >= n || rcut[i2])) {
                    cout << "possible" << endl;
                    return 0;
                }
            }
        }
    }
    cout << "impossible" << endl;
}
