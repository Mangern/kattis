#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;

#define sz(v) (int)(v).size()
#define rep(i,s,t) for (int i = (s); i < (t); ++i)

ll mod;

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

int matInv(vector<vector<ll>>& A) {
	int n = sz(A); vi col(n);
	vector<vector<ll>> tmp(n, vector<ll>(n));
	rep(i,0,n) tmp[i][i] = 1, col[i] = i;

	rep(i,0,n) {
		int r = i, c = i;
		rep(j,i,n) rep(k,i,n) if (A[j][k]) {
			r = j; c = k; goto found;
		}
		return i;
found:
		A[i].swap(A[r]); tmp[i].swap(tmp[r]);
		rep(j,0,n)
			swap(A[j][i], A[j][c]), swap(tmp[j][i], tmp[j][c]);
		swap(col[i], col[c]);
		ll v = modpow(A[i][i], mod - 2);
		rep(j,i+1,n) {
			ll f = A[j][i] * v % mod;
			A[j][i] = 0;
			rep(k,i+1,n) A[j][k] = (A[j][k] - f*A[i][k]) % mod;
			rep(k,0,n) tmp[j][k] = (tmp[j][k] - f*tmp[i][k]) % mod;
		}
		rep(j,i+1,n) A[i][j] = A[i][j] * v % mod;
		rep(j,0,n) tmp[i][j] = tmp[i][j] * v % mod;
		A[i][i] = 1;
	}

	for (int i = n-1; i > 0; --i) rep(j,0,i) {
		ll v = A[j][i];
		rep(k,0,n) tmp[j][k] = (tmp[j][k] - v*tmp[i][k]) % mod;
	}

	rep(i,0,n) rep(j,0,n)
		A[col[i]][col[j]] = tmp[i][j] % mod + (tmp[i][j] < 0)*mod;
	return n;
}

int main() {
    ll T;
    cin >> T;
    while (T-->0) {
        cin >> mod;

        string s;
        cin >> s;

        int n = s.length();

        vector<vector<ll>> A(n, vector<ll>(n));

        for (ll i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                A[i][j] = modpow(i+1, j);
            }
        }
        matInv(A);

        vector<ll> p(n);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*')p[i] = 0;
            else p[i] = s[i] - 'a' + 1;
        }
        vector<ll> a(n);
        for (int i = 0; i < n; ++i) {
            a[i] = 0;
            for (int j = 0; j < n; ++j) {
                a[i] += p[j] * A[i][j] % mod;
                a[i] %= mod;
            }
        }
        for (auto x : a)cout << x << ' ';
        cout << '\n';
    }
}
