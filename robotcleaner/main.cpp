#include <bits/stdc++.h>
using namespace std;
using ii = pair<int, int>;

int main() {
    int w, h;
    cin >> w >> h;
    set<ii> rem;
    for (int i = 1; i <= min(w, h); ++i) {
        rem.insert({i, i});
    }

    int x, y;
    cin >> x >> y;

    rem.erase(ii{x,y});

    int m;
    cin >> m;
    bool done = rem.empty();
    while (m-->0) {
        int l;
        cin >> l;
        string dir;
        cin >> dir;

        int dx, dy;
        if (dir == "up") {
            dx = 0;
            dy = 1;
        } else if (dir == "down") {
            dx = 0;
            dy = -1;
        } else if (dir == "left") {
            dx = -1;
            dy = 0;
        } else if (dir == "right") {
            dx = 1;
            dy = 0;
        }

        for (int i = 0; i < l; ++i) {
            x += dx;
            y += dy;
            rem.erase(ii{x, y});
        }

        if (done) continue;
        cout << x << " " << y << endl;
        done = rem.empty();
    }
}
