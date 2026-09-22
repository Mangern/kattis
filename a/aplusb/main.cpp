#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using ll = long long;
 
#define rep(i,lo,hi) for (int i = (lo); i < (hi); ++i)
#define sz(v) (v).size()
#define all(v) begin(v), end(v)
 
typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
 
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

int main() {
	int n;
	cin >> n;

    constexpr ll OFF = 50000;

    vector<ll> freq(2 * OFF + 1, 0);

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        ++freq[x+OFF];
    }

    vd a(freq.size(), 0.0);
    for (int i = 0; i < freq.size(); ++i) {
        a[i] = (double)freq[i];
    }

    auto res = conv(a,a);

    ll ans = 0;
    for (ll i = OFF; i < res.size(); ++i) {
        ll cnt = round(res[i]);

        if (cnt == 0) continue;

        ll target = i - 2 * OFF;

        if (target > OFF) continue;

        // cnt is number of ways to make x but:
        // adding number to itself is counted too much

        if (target % 2 == 0) {
            // Subtract x + x == target
            cnt -= freq[target/2+OFF] * freq[target/2+OFF];
        }
        // subtract 0 + x == x and x + 0 == x
        if (target != 0) {
            cnt -= 2 * freq[0+OFF] * freq[target+OFF];
        } else {
            // once subtracted above
            // cnt -= freq[0+OFF] * freq[0+OFF];
        }
        //
        // cout << "You can make " << target << " in " << cnt << " ways" << endl;

        ans += cnt * freq[target+OFF];

        // cnt == sum(a[k] * a[i-k] for all k)
    }
    ll f0 = freq[0+OFF];
    for (ll x = -OFF; x <= OFF; ++x) {
        if (x == 0) {
            // 0 + 0 == 0
            ans += f0 * (f0 - 1) * (f0 - 2);
        } else {
            // 0 + x == x
            ll fx = freq[x+OFF];
            ans += 2 * f0 * fx * (fx - 1);

            // x + x == 2 * x
            if (0 <= 2*x+OFF && 2*x+OFF < (ll)freq.size()) {
                ans += fx * (fx - 1) * freq[2*x+OFF];
            }
        }
    }


    cout << ans << endl;

	return 0;
}
