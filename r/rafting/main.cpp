#include <bits/stdc++.h>
using namespace std;

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

typedef Point<double> P;
double segDist(P& s, P& e, P& p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

int main() {
    int T;
    cin >> T;
    while (T-->0) {
        int ni, no;
        cin >> ni;

        vector<P> inner(ni);
        for (auto &p : inner)cin >> p.x >> p.y;
        cin >> no;
        vector<P> outer(no);
        for (auto &p : outer)cin >> p.x >> p.y;

        double gmin = numeric_limits<double>::infinity();
        for (auto p : inner) {
            for (int i = 0; i < no; ++i) {
                int j = (i + 1) % no;

                gmin = min(gmin, segDist(outer[i], outer[j], p));
            }
        }
        for (auto p : outer) {
            for (int i = 0; i < ni; ++i) {
                int j = (i + 1) % ni;
                gmin = min(gmin, segDist(inner[i], inner[j], p));
            }
        }

        cout << setprecision(12) << fixed << gmin/2 << endl;
    }
}
