#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define sz(v) (int)(v).size()

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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a%b);
}

int main() {
    int n;
    cin >> n;

    vector<Point<ll>> pts;
    for (int i = 0; i < n; ++i) {
        auto& p = pts.emplace_back();
        cin >> p.x >> p.y;
    }

    ll a2 = abs(polygonArea2(pts));

    ll b = 0;
    for (int i = 0; i < n; ++i) {
        auto pa = pts[i];
        auto pb = pts[(i+1)%n];

        ll dx = pb.x - pa.x;
        ll dy = pb.y - pa.y;
        ll g = gcd(abs(dx), abs(dy));
        b += g;
    }
    // 2A = 2i + b - 2
    cout <<  (a2 - b + 2) / 2 << endl;

}
