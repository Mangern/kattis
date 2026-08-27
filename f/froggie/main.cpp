#include <bits/stdc++.h>
using namespace std;

int l, w;
struct car {
    int o, i, s;
};

bool canmove(const car& c, int cdir, int pos, int t) {
    int cstart;

    if (cdir == -1) {
        cstart = w - 1 - c.o;
    } else {
        cstart = c.o;
    }

    if (c.s == 0) {
        while (cstart > pos)cstart -= c.i;
        while (cstart < pos)cstart += c.i;
        return cstart != pos;
    }

    if (cdir == -1) {
        cstart -= c.s * t;
        while (cstart > pos)cstart -= c.i;
        while (cstart <= pos)cstart += c.i;
        return cstart - c.s > pos;
    } else {
        cstart += c.s * t;
        while (cstart < pos)cstart += c.i;
        while (cstart >= pos)cstart -= c.i;
        return cstart + c.s < pos;
    }
}

int main() {
    cin >> l >> w;

    vector<car> cars(l);
    for (auto& c : cars) {
        cin >> c.o >> c.i >> c.s;
    }

    int x;
    cin >> x;
    int y = l;

    string moves;
    cin >> moves;

    int t = 0;

    for (char c : moves) {
        if (c == 'U') {
            if (y == 0) {
                cout << "safe" << endl;
                return 0;
            }
            if (!canmove(cars[y-1], (y-1)&1?-1:1, x, t)) {
                cout << "squish" << endl;
                return 0;
            }
            --y;
        } else if (c == 'D') {
            if (!canmove(cars[y+1], (y+1)&1?-1:1, x, t)) {
                cout << "squish" << endl;
                return 0;
            }
            ++y;
        } else if (c == 'L') {
            if (y < l) {
                if (!canmove(cars[y], y&1?-1:1, x-1, t)) {
                    cout << "squish" << endl;
                    return 0;
                }
                if (!(y&1)) {
                    int cstart = cars[y].o;
                    cstart += cars[y].s * t;
                    while (cstart > x-1)cstart -= cars[y].i;
                    while (cstart < x-1)cstart += cars[y].i;
                    if (cstart == x-1) {
                        cout << "squish" << endl;
                        return 0;
                    }
                }
            }
            --x;
        } else /*if (c == 'R')*/ {
            if (y < l) {
                if (!canmove(cars[y], y&1?-1:1, x+1, t)) {
                    cout << "squish" << endl;
                    return 0;
                }
                if ((y&1)) {
                    int cstart = w - 1 - cars[y].o;
                    cstart -= cars[y].s * t;
                    while (cstart < x+1)cstart += cars[y].i;
                    while (cstart > x+1)cstart -= cars[y].i;
                    if (cstart == x+1) {
                        cout << "squish" << endl;
                        return 0;
                    }
                }
            }
            ++x;
        }
        t += 1;
    }
    cout << "squish" << endl;
}
