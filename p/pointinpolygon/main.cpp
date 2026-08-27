#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mxN = 1005;

#define point complex<ll>

#define X real()
#define Y imag()

int n, q;
point pts[mxN];

const ll INF = 1e9+7;
const point infinity = {INF, INF};

ll cross_sign(point a, point b, point c) {
    point u = b - a;
    point v = c - a;
    ll cp = (conj(u) * v).Y;
    return (cp > 0) - (cp < 0);
}

bool mid(point a, point b, point c) {
    vector<point> v = {a,b,c};
    sort(begin(v), end(v), [](auto &A, auto &B) {
        return (A.X == B.X) ? (A.Y < B.Y) : (A.X < B.X);
    });
    return v[1] == c;
}

// crosses ray defined by y = ray.y, x >= ray.x
bool seg_crosses(point seg_a, point seg_b, point p) {
    ll cp1 = cross_sign(seg_a, seg_b, p);
    ll cp2 = cross_sign(seg_a, seg_b, infinity);
    ll cp3 = cross_sign(p, infinity, seg_a);
    ll cp4 = cross_sign(p, infinity, seg_b);

    if (cp1 * cp2 < 0 && cp3 * cp4 < 0) return 1;
    if (cp3 == 0 && mid(p, infinity, seg_a) && cp4 < 0) return 1;
    if (cp4 == 0 && mid(p, infinity, seg_b) && cp3 < 0) return 1;

    return 0;
}

void test() {
    cin >> n;
    if (!n) {
        exit(0);
    }

    for (int i = 0; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        pts[i] = {x, y};
    }

    cin >> q;

    while (q-->0) {
        ll x, y;
        cin >> x >> y;

        point p = {x,y};

        bool on = false;
        int crossings = 0;
        for (int i = 0; i < n; ++i) {
            ll cp = cross_sign(pts[i], pts[(i+1)%n], p);
            if (cp == 0 && mid(pts[i], pts[(i + 1) %n], p)) {
                on = 1;
                break;
            }
            if (seg_crosses(pts[(i+n-1)%n], pts[i], p)) {
                //cout << "Crosses: (" << pts[(i+n-1)%n].X << ", " 
                //    << pts[(i+n-1)%n].Y << ") - (" << pts[i].X << ", " << pts[i].Y << ")" << endl;
                ++crossings;
            }
        }

        if (on) {
            cout << "on" << endl;
        } else {
            cout << (crossings % 2 ? "in" : "out") << endl;
        }
    }
}

int main() {
    for (;;) test();
}
