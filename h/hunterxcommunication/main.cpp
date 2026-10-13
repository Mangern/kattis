#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;

#define sz(v) (int)(v).size()
#define rep(i, s, t) for (int i = (s); i < (t); ++i)

const ll mod = (119 << 23) + 1, root = 62; // = 998244353

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, modpow(root, mod >> s)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s),
	    n = 1 << B;
	ll inv = modpow(n, mod - 2);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n)
		out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int main() {
    vl kernel(10,1);
    ll n;
    cin >> n;

    ll big = (n + 1) / 2;
    ll small = n / 2;

    vl f, g;
    {
        f.assign(1,1);
        vl b = kernel;
        ll e = big - 1;
        while (e) {
            if (e & 1) {
                f = conv(f, b);
            }
            b = conv(b, b);
            e /= 2;
        }

        kernel[0] = 0;
        f = conv(f, kernel);
        kernel[0] = 1;
    }

    {
        g.assign(1, 1);
        vl b = kernel;
        ll e = small;
        while (e) {
            if (e & 1) {
                g = conv(g, b);
            }
            b = conv(b, b);
            e /= 2;
        }
    }

    vl h = conv(f, g);
    ll ans = 0;
    for (ll s = 0; s < sz(h); ++s) {
        ans += h[s] * h[s] % mod;
        ans %= mod;
    }
    if (n == 1)++ans; // 0 is a 1 digit number...
    cout << ans << endl;
}
