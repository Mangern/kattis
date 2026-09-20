#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
const int mxN = 2e5+3;
 
int n, q;

struct Node {
	Node *l = 0, *r = 0;
	int lo, hi;

    // This node may store a arithmetic sequence to be added to this subtree:
    // [base, base + increment, base + 2 * increment, ...]
    ll mbase = 0;
    ll mincrement = 0;

	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf

	ll query(int index) {
        if (lo + 1 == hi) return mbase;
		push();
        if (index < l->hi) {
            return l->query(index);
        }
        return r->query(index);
	}

    void update(int L, int R, ll base, ll inc) {
        if (R <= lo || hi <= L) return;
        // cout << "Updating node " << lo << " " << hi << " with " << base << " " << inc << " in [" << L << " " << R << ")" << endl;
        if (L <= lo && hi <= R) {
            mbase += base + (lo - L) * inc;
            mincrement += inc;
        } else {
            push();
            l->update(L, R, base, inc);
            r->update(L, R, base, inc);
        }
    }

	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
        if (mbase || mincrement) {
            l->update(lo, hi, mbase, mincrement);
            r->update(lo, hi, mbase, mincrement);
            mbase = 0;
            mincrement = 0;
        }
	}
};
 
int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
 
    vector<ll> arr(n, 0);
 
    Node* segtree = new Node(0, n);
 
    while (q-->0) {
        char t;
        cin >> t;

        int l, r;
        cin >> l >> r;
        --l;

        if (t == 'R') {
            segtree->update(l, r, 1, 0);
        } else if (t == 'D') {
            segtree->update(l, r, -1, 0);
        } else if (t == 'H') {
            if ((r-l) & 1) {
                int num_inc = (r-l+1)/2;
                segtree->update(l, l + num_inc, 1, 1);
                segtree->update(l + num_inc, r, num_inc - 1, -1);
            } else {
                int num_inc = (r-l)/2;
                segtree->update(l, l + num_inc, 1, 1);
                segtree->update(l+num_inc, r, num_inc, -1);
            }
        } else if (t == 'V') {
            if ((r-l) & 1) {
                int num_inc = (r-l+1)/2;
                segtree->update(l, l + num_inc, -1, -1);
                segtree->update(l + num_inc, r, -num_inc + 1, 1);
            } else {
                int num_inc = (r-l)/2;
                segtree->update(l, l + num_inc, -1, -1);
                segtree->update(l+num_inc, r, -num_inc, 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << segtree->query(i) << '\n';
    }
    return 0;
}
