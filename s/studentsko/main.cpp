#include <bits/stdc++.h>
using namespace std;

#define sz(v) (int)(v).size()

int lis(const vector<int>& S) {
	if (S.empty()) return {};
	vector<int> prev(sz(S));
	typedef pair<int, int> p;
	vector<p> res;
	for(int i=0;i < sz(S); ++i) {
		auto it = lower_bound(begin(res), end(res), p{S[i], i});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = sz(res), cur = res.back().second;
    return L;
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);

    sort(begin(idx), end(idx), [&](auto i, auto j) { return a[i] < a[j]; });

    vector<int> b(n);

    for (int i = 0; i < n; ++i) {
        int r = i / k;
        b[idx[i]] = r;
    }

    int L = lis(b);
    cout << n - L << endl;
}
