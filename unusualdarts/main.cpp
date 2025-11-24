#include <bits/stdc++.h>
using namespace std;

#define rep(i,lo,hi) for(int i = (lo); i < (hi); ++i)
#define sz(v) ((int)(v).size())

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> bool segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
        return 1;
    return 0;
}

const double EPS = 1e-5;

void testCase() {
    using P = Point<double>;

    vector<P> pts(7);

    for (int i = 0; i < 7; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    double bob;
    cin >> bob;
    
    vector<int> idx(7);
    iota(begin(idx), end(idx), 0);

    vector<P> poly(7);
    poly[0] = pts[0];
    do {
        for (int i = 1; i < 7; ++i) {
            poly[i] = (pts[idx[i]]);
        }

        bool bad = 0;

        for (int i = 0; i < poly.size(); ++i) {
            int ni = (i + 1) % poly.size();

            for (int j = 0; j < i; ++j) {
                int nj = (j + 1) % poly.size();

                if (segInter(poly[i], poly[ni], poly[j], poly[nj])) {
                    bad = 1;
                    break;
                }
            }
        }

        if (bad)continue;

        double ar = abs(polygonArea2(poly)) / 2.0 / 4;

        if (abs(ar*ar*ar - bob) <= EPS) break;
    } while (next_permutation(begin(idx)+1, end(idx)));

    for (auto i : idx)cout << i+1 << " ";
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    while (t-->0) {
        testCase();
    }
}
