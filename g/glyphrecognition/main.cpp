#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) ((int)v.size())
#define rep(i, lo, hi) for(int i = (lo); i < (hi); ++i)

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

using P = Point<double>;

constexpr double EPS = 1e-8;
int main() {
    int n;
    cin >> n;

    vector<P> points(n);

    for (int i = 0; i < n; ++i) {
        cin >> points[i].x >> points[i].y;
    }

    int opt = 3;
    double opta = 0.0;
    for (int k = 3; k <= 8; ++k) {
        double alpha = 2 * M_PIf64 / (double)k;

        double amin = numeric_limits<double>::infinity();
        double amax = -numeric_limits<double>::infinity();
        for (auto p : points) {
            double ang = atan2(p.y, p.x);
            if (ang < 0) ang += 2 * M_PIf64;
            int kdrant = floor(ang / alpha);
            ang -= alpha * kdrant;
            double inner = abs(alpha / 2 - ang);
            double len = p.dist();
            double t = len * cos(inner);
            assert(t>0);
            double s = tan(alpha / 2) * t;
            double ar = s * t * k;
            amin = min(amin, ar);
            amax = max(amax, ar);
        }

        double a = amin / amax;
        if (a > opta) {
            opta = a;
            opt = k;
        }
    }

    cout << opt << " " << setprecision(12) << fixed << opta << endl;
}
