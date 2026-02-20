#include <bits/stdc++.h>
using namespace std;
using ll = long long;

using rect = array<ll, 4>;

#define top(r) ((r)[0])
#define bot(r) ((r)[1])
#define lft(r) ((r)[2])
#define rgt(r) ((r)[3])

ostream &operator<<(ostream &os, const rect& r) {
    return os << top(r) << " " << lft(r) << " " << bot(r) << " " << rgt(r);
}

int main() {
    ll k;
    cin >> k;
    string s;
    cin >>s;

    rect box;
    rect cur;

    ll r, c;
    cin >> r >> c;

    cur = {r,r,c,c};
    box = {min(0LL,r), max(0LL,r), min(0LL,c), max(0LL,c)};

    for (int i = k - 1; i >= 0; --i) {
        // cout << cur << " " << s[i] << endl;
        switch (s[i]) {
            case '<':
                if (lft(cur) == lft(box)) {
                    if (rgt(cur) < rgt(box)) {
                        ++rgt(cur);
                    }
                } else if (rgt(cur) == rgt(box)) {
                    if (lft(cur) == rgt(cur)) {
                        ++lft(cur);
                        ++rgt(cur);
                        ++rgt(box);
                    } else {
                        ++lft(cur);
                    }
                } else {
                    ++lft(cur);
                    ++rgt(cur);
                }
                break;
            case '>':
                if (rgt(cur) == rgt(box)) {
                    if (lft(cur) > lft(box)) {
                        --lft(cur);
                    }
                } else if (lft(cur) == lft(box)) {
                    if (lft(cur) == rgt(cur)) {
                        --lft(cur);
                        --rgt(cur);
                        --lft(box);
                    } else {
                        --rgt(cur);
                    }
                } else {
                    --lft(cur);
                    --rgt(cur);
                }
                break;
            case '^':
                if (top(cur) == top(box)) {
                    if (bot(cur) < bot(box)) {
                        ++bot(cur);
                    }
                } else if (bot(cur) == bot(box)) {
                    if (top(cur) == bot(cur)) {
                        ++top(cur);
                        ++bot(cur);
                        ++bot(box);
                    } else {
                        ++top(cur);
                    }
                } else {
                    ++top(cur);
                    ++bot(cur);
                }
                break;
            case 'v':
                if (bot(cur) == bot(box)) {
                    if (top(cur) > top(box)) {
                        --top(cur);
                    }
                } else if (top(cur) == top(box)) {
                    if (top(cur) == bot(cur)) {
                        --top(cur);
                        --bot(cur);
                        --top(box);
                    } else {
                        --bot(cur);
                    }
                } else {
                    --top(cur);
                    --bot(cur);
                }
                break;
        }
    }

    // is 0 0 in cur?
    if (0 < lft(cur) || rgt(cur) < 0 || 0 < top(cur) || bot(cur) < 0) {
        cout << -1 << endl;
        return 0;
    }

    ll n = (bot(box) - top(box) + 1);
    ll m = (rgt(box) - lft(box) + 1);
    // cout << n << " " << m << endl;
    cout << n * m << endl;
}
