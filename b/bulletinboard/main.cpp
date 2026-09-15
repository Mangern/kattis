#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using vi = vector<int>;
using ii = pair<int, int>;

const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0;
    ii maxi = {-inf, 0};
    ii mini = {inf, 0};
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	ii querymax(int L, int R) {
		if (R <= lo || hi <= L) return {-inf, 0};
		if (L <= lo && hi <= R) return maxi;
		push();
		return combine_max(l->querymax(L, R), r->querymax(L, R));
	}
    ii combine_max(ii lft, ii rgt) {
        if (lft.first > rgt.first) {
            return lft;
        }
        if (rgt.first > lft.first) {
            return rgt;
        }
        return {lft.first, lft.second + rgt.second};
    }
    ii combine_min(ii lft, ii rgt) {
        if (lft.first < rgt.first) {
            return lft;
        }
        if (rgt.first < lft.first) {
            return rgt;
        }
        return {lft.first, lft.second + rgt.second};
    }
    ii querymin(int L, int R) {
		if (R <= lo || hi <= L) return {inf, 0};
		if (L <= lo && hi <= R) return mini;
		push();
		return combine_min(l->querymin(L, R), r->querymin(L, R));
    }
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
            mset = x, madd = 0;
            maxi.first = x;
            maxi.second = hi - lo;
            mini.first = x;
            mini.second = hi - lo;
        }
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			maxi = combine_max(l->maxi, r->maxi);
            mini = combine_min(l->mini, r->mini);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			maxi.first += x;
            mini.first += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			maxi = combine_max(l->maxi, r->maxi);
            mini = combine_min(l->mini, r->mini);
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

#define forever for(;;)

int main() {
    forever {
        int n;
        cin >> n;
        if (!n) break;
        int w, h;
        cin >> w >> h;

        Node* tree = new Node(0, h);
        tree->set(0, h + 1, 0);
        // x, yl, yh, delta
        vector<array<int, 4>> events;

        for (int i = 0; i < n; ++i) {
            int xl, yl, xh, yh;
            cin >> xl >> yl >> xh >> yh;

            events.push_back({xl, yl, yh, 1});
            events.push_back({xh, yl, yh, -1});
        }
        sort(events.begin(), events.end());

        events.push_back({w, 0, h, 0});

        int px = 0;
        ll empty_area = 0;
        ll max_val = -1;
        ll max_cnt = 0;
        for (auto [x, yl, yh, delta] : events) {

            auto [mini, mini_cnt] = tree->querymin(0, h);
            if (mini == 0) {
                empty_area += mini_cnt * (x - px);
            }

            auto [maxi, maxi_cnt] = tree->querymax(0, h);

            if (maxi > max_val) {
                max_val = maxi;
                max_cnt = 0;
            }
            if (maxi >= max_val) {
                max_cnt += maxi_cnt * (x - px);
            }

            tree->add(yl, yh, delta);

            px = x;
        }

        cout << empty_area << " " << max_val << " " << max_cnt << endl;
    }
}
