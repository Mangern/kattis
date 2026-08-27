#include <bits/stdc++.h>
using namespace std;
using ll = __int128;

#define rep(i, lo, hi) for (int i = (lo); i < (hi); ++i)
#define sz(v) ((int)v.size())

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

int main() {
    int n;
    cin >> n;
    vector<Point<ll>> poly(n);

    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        poly[i].x = x;
        poly[i].y = y;
    }

    ll ar = polygonArea2(poly);
    if (ar < 0)ar = -ar;

    ll sm = 0;

    {
        // i (j - k)
        ll kysum = poly[n-1].y;
        ll kxsum = poly[n-1].x;

        vector<ll> jxvals(n, 0);
        vector<ll> jyvals(n, 0);
        vector<ll> jxkyvals(n, 0);
        vector<ll> jykxvals(n, 0);
        for (ll i = n - 2; i >= 0; --i) {
            jxvals[i] = (n - 1 - i) * poly[i].x - kxsum;
            jyvals[i] = (n - 1 - i) * poly[i].y - kysum;

            jxkyvals[i] = poly[i].x * kysum;
            jykxvals[i] = poly[i].y * kxsum;

            kxsum += poly[i].x;
            kysum += poly[i].y;
        }
        for (int i = n - 2; i >= 0; --i) {
            jxvals[i] += jxvals[i+1];
            jyvals[i] += jyvals[i+1];

            jxkyvals[i] += jxkyvals[i+1];
            jykxvals[i] += jykxvals[i+1];
        }

        for (ll i = 0; i < n - 1; ++i) {
            sm += poly[i].x * jyvals[i+1];
            sm -= poly[i].y * jxvals[i+1];
            sm += jxkyvals[i+1];
            sm -= jykxvals[i+1];
        }
    }
    cout << setprecision(10) << fixed << (double)sm / (double)ar << endl;
}
