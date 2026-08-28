#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;

struct item {
    int u;
    int v;
};

bool operator<(const item& i1, const item& i2) {
    if (i1.v != i2.v) {
        return i1.v < i2.v;
    }
    if (i1.v % 2 == 0) {
        // down
        return i1.u < i2.u;
    } else {
        // right, cannot combine
        return i1.u > i2.u;
    }
}

template<class I> vi lis(const vector<I>& S) {
	if (S.empty()) return {};
	vi prev(S.size());
	typedef pair<I, int> p;
	vector<p> res;
	for(int i = 0; i < (int)S.size(); ++i) {
		auto it = lower_bound(begin(res), end(res), p{S[i], 0});
		if (it == res.end()) res.emplace_back(), it = res.end()-1;
		*it = {S[i], i};
		prev[i] = it == res.begin() ? 0 : (it-1)->second;
	}
	int L = res.size(), cur = res.back().second;
	vi ans(L);
	while (L--) ans[L] = cur, cur = prev[cur];
	return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;

    vector<item> items;
    for (int i = 0; i < n; ++i) {
        {
            int l = i;
            int r = a[i] - l - 1;
            if (r >= 0) {
                items.push_back(item{
                    2 * l + 1, 2 * r
                });
            }
        }
        {
            int r = (n-1)-i;
            int l = a[i] - r - 1;
            if (l >= 0) {
                items.push_back(item{
                    2 * l, 2 * r + 1
                });
            }
        }
    }

    sort(begin(items), end(items), [] (auto i1, auto i2){
        if (i1.u != i2.u) return i1.u < i2.u;
        if (i1.u % 2 == 0) {
            // right
            return i1.v < i2.v;
        } else {
            // down. cannot combine
            return i1.v > i2.v;
        }
    });
    vi idxs = lis(items);

    cout << n - (int)idxs.size() << endl;
}
