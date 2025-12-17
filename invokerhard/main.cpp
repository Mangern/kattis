#include <bits/stdc++.h>
using namespace std;
using vec3 = array<double, 3>;

double operator*(const vec3& v1, const vec3& v2) {
    return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

vec3 cross(const vec3& v1, const vec3& v2) {
    return {
        v1[1]*v2[2] - v1[2] * v2[1],
        v1[2]*v2[0] - v1[0] * v2[2],
        v1[0]*v2[1] - v1[1] * v2[0]
    };
}

vec3 operator*(const double& scale, const vec3& v) {
    return {scale * v[0], scale * v[1], scale * v[2]};
}

vec3 operator+(const vec3& v1, const vec3& v2) {
    return {v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]};
}

struct Quaternion {
    double eta;
    vec3 eps;

    Quaternion() { eta = 0.0; eps = {0}; }
    Quaternion(double q0, double q1, double q2, double q3) {
        eta = q0;
        eps = {q1,q2,q3};
    }

    Quaternion(const double& eta, const vec3& eps) : eta(eta), eps(eps) {}

    Quaternion inv() {
        double scale = eta*eta 
                     + eps[0]*eps[0]
                     + eps[1]*eps[1]
                     + eps[2]*eps[2];
        return 1 / scale * Quaternion(eta, -1.0 * eps);
    }

    friend Quaternion operator*(const double& scale, const Quaternion& q) {
        return Quaternion(scale*q.eta, scale*q.eps[0], scale*q.eps[1], scale*q.eps[2]);
    }

    Quaternion operator*(const Quaternion& other) {
        return Quaternion{
            eta * other.eta - eps * other.eps,
            eta * other.eps + other.eta * eps + cross(eps, other.eps)
        };
    }
};


int main() {
    Quaternion q1, q2;
    cin >> q1.eta >> q1.eps[0] >> q1.eps[1] >> q1.eps[2];
    cin >> q2.eta >> q2.eps[0] >> q2.eps[1] >> q2.eps[2];

    Quaternion res = q1 * q2.inv();

    cout << setprecision(10) << fixed << res.eta << " " << res.eps[0] << " " << res.eps[1] << " " << res.eps[2] << endl;
}
