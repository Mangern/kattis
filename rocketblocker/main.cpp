#include <bits/stdc++.h>
using namespace std;

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
	for(int i = 0; i < sz(v)-1; ++i) a += v[i].cross(v[i+1]);
	return a;
}

using P = Point<double>;

int main() {
    double r;
    cin >> r;

    int n;
    cin >> n;

    vector<P> poly;

    for (int i = 0; i < n; ++i) {
        double x, y;
        cin >> x >> y;
        poly.emplace_back(x, y);
    }

    double ar = abs(polygonArea2(poly)) / 2.0;

    for (int i = 0; i < n; ++i) {
        P cur = poly[i];
        P nxt = poly[(i+1)%n];
        ar += r * (nxt - cur).dist(); // rect. padding
        P seg1 = (cur - nxt).perp().unit();
        P seg2 = (nxt - poly[(i+2)%n]).perp().unit();
        double alpha = seg2.angle() - seg1.angle();
        if (alpha < 0)alpha += 2 * M_PI;
        ar += r * r * alpha / 2.0;
    }

    double ans = ar / (1000.0 * 1000.0);

    cout << setprecision(12) << fixed << ans << endl;
}
