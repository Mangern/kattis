#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vi = vector<ll>;

const ll inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	ll lo, hi, mset = inf, madd = 0, val = 0;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of 0

	ll query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, ll x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};

int main() {
    int n;
    cin >> n;

    vector<ll> coords;

    vector<pair<ll, ll>> qrs;

    for (int i = 0; i < n; ++i) {
        ll x, s;
        cin >> x >> s;

        qrs.emplace_back(x, s);

        coords.emplace_back(x);
        coords.emplace_back(x + s);
    }
    sort(begin(coords), end(coords));
    coords.erase(unique(begin(coords), end(coords)), end(coords));

    int m = (int)coords.size();
    Node st(0, m);

    for (auto [x, s] : qrs) {
        int l = lower_bound(begin(coords), end(coords), x) - begin(coords);
        int r = lower_bound(begin(coords), end(coords), x + s) - begin(coords);

        ll mx = st.query(l, r);
        st.set(l, r, mx + s);
        cout << st.query(0, m) << '\n';
    }
}
