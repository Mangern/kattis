#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = array<ll,2>;

#define rep(i, lo, hi) for(int i = (lo); i < (hi); ++i)
#define sz(v) ((int)v.size())

const double EPS = 1e-7;

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
    double D, L;
    cin >> D >> L;
    vector<ii> poly(n);
    ll mxy = -1e10;
    ll mny = 1e10;

    for (auto &[x, y] : poly) {
        cin >> x >> y;
        mxy = max(mxy, y);
        mny = min(mny, y);
    }
    reverse(begin(poly), end(poly));
    int mini = 0;

    for (int i = 0; i < n; ++i) {
        if (poly[i][1] < poly[mini][1] || (poly[i][1] == poly[mini][1] && poly[i][0] < poly[mini][0])) {
            mini = i;
        }
    }
    vector<ii> tmp;

    for (int i = mini; i < n; ++i) {
        tmp.push_back(poly[i]);
    }
    for (int i = 0; i < mini; ++i) {
        tmp.push_back(poly[i]);
    }


    swap(tmp, poly);
    vector<double> dx(n);

    for (int i = 0; i < n; ++i) {
        if (poly[i][1] == mxy)break;

        dx[i] = (double)(poly[i+1][0] - poly[i][0]) / (double)(poly[i+1][1] - poly[i][1]);
    }

    for (int i = n - 1; i >= 0; --i) {
        if (poly[i][1] == mxy) break;
        dx[i] = (double)(poly[i-1][0] - poly[i][0]) / (double)(poly[i-1][1] - poly[i][1]);
    }

    double lo = mny;
    double hi = mxy;

    using P = Point<double>;

    while (abs(hi - lo) > EPS) {
        double yval = (lo+hi)/2.0;

        vector<P> pcut;

        double lx;
        for (int i = 0; i < n; ++i) {
            pcut.push_back(P{(double)poly[i][0], (double)poly[i][1]});
            if (poly[i+1][1] > yval) {
                lx = poly[i][0] + dx[i] * (yval - poly[i][1]);
                pcut.push_back(P{lx, yval});
                break;
            }
        }
        double rx;
        int ei;

        for (int i = n - 1; i >= 0; --i) {
            if (poly[i-1][1] > yval) {
                rx = poly[i][0] + dx[i] * (yval - poly[i][1]);
                ei = i;
                break;
            }
        }

        pcut.push_back(P{rx, yval});
        for (int i = ei; i < n; ++i) {
            pcut.push_back(P{(double)poly[i][0], (double)poly[i][1]});
        }

        double ar = abs(polygonArea2(pcut)) / 2.0;
        if (D * ar < L * 1000) {
            lo = yval;
        } else {
            hi = yval;
        }
    }

    cout << setprecision(2) << fixed << lo << endl;
}
