#include <bits/stdc++.h>
using namespace std;


template<class T> struct Point3D {
	typedef Point3D P;
	T x, y, z;
	explicit Point3D(T x=0, T y=0, T z=0) : x(x), y(y), z(z) {}
	bool operator<(P p) const {
		return tie(x, y, z) < tie(p.x, p.y, p.z); }
	bool operator==(P p) const {
		return tie(x, y, z) == tie(p.x, p.y, p.z); }
	P operator+(P p) const { return P(x+p.x, y+p.y, z+p.z); }
	P operator-(P p) const { return P(x-p.x, y-p.y, z-p.z); }
	P operator*(T d) const { return P(x*d, y*d, z*d); }
	P operator/(T d) const { return P(x/d, y/d, z/d); }
	T dot(P p) const { return x*p.x + y*p.y + z*p.z; }
	P cross(P p) const {
		return P(y*p.z - z*p.y, z*p.x - x*p.z, x*p.y - y*p.x);
	}
	T dist2() const { return x*x + y*y + z*z; }
	double dist() const { return sqrt((double)dist2()); }
	//Azimuthal angle (longitude) to x-axis in interval [-pi, pi]
	double phi() const { return atan2(y, x); } 
	//Zenith angle (latitude) to the z-axis in interval [0, pi]
	double theta() const { return atan2(sqrt(x*x+y*y),z); }
	P unit() const { return *this/(T)dist(); } //makes dist()=1
	//returns unit vector normal to *this and p
	P normal(P p) const { return cross(p).unit(); }
	//returns point rotated 'angle' radians ccw around axis
	P rotate(double angle, P axis) const {
		double s = sin(angle), c = cos(angle); P u = axis.unit();
		return u*dot(u)*(1-c) + (*this)*c - cross(u)*s;
	}
};

typedef Point3D<double> P;
double segDist(P s, P e, P p) {
	if (s==e) return (p-s).dist();
	auto d = (e-s).dist2(), t = min(d,max(.0,(p-s).dot(e-s)));
	return ((p-s)*d-(e-s)*t).dist()/d;
}

int main() {
    const double R = 40000.0 / 2.0 / M_PI;
    for (;;) {
        int k, m;
        cin >> k >> m;
        if (!k) break;
        vector<Point3D<double>> sat(k), targ(m);
        vector<int> ans(m, 0);
        for (int i = 0; i < k; ++i) {
            cin >> sat[i].x >> sat[i].y >> sat[i].z;
        }
        for (int i = 0; i < m; ++i) {
            cin >> targ[i].x >> targ[i].y >> targ[i].z;
        }

        for (int i = 0; i < k; ++i) {
            for (int j = 0; j < m; ++j) {
                Point3D<double> s = sat[i];
                Point3D<double> e = targ[j];
                Point3D<double> p{0.0,0.0,0.0};
                double sd = segDist(s, e, p);
                if (abs(sd-R)<=2e-8) {
                    ans[j] = 1;
                }
            }
        }
        cout << accumulate(begin(ans), end(ans),0) << endl;
    }
}
