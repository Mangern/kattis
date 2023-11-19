#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using C = complex<double>;
using vC = vector<C>;
void F(vector<C>& a, bool inv = false) {
    int n = a.size();
    if (n > 1){
    vC a0(n>>1), a1(n>>1);
    for (int i = 0; i < n; ++i) {
        if (i&1)a1[i>>1] = a[i];
        else a0[i>>1] = a[i];
    }
    F(a0, inv);
    F(a1, inv);
    C w(1.0);
    C wn = polar(1.0, 2 * M_PI / n * (inv ? -1 : 1));
    for (int i = 0; i < (n >> 1); ++i) {
        a[i]=a0[i]+w*a1[i];
        a[i+(n>>1)]=a0[i]-w*a1[i];
        w *= wn;
    }
    }
}
int main() {
    string s;
    cin >> s;
    int n = s.length();
    int g = 2*n-1;
    n = 1 << (32-__builtin_clz(g));
    vC a(n, 0);
    vC b(n, 0);
    for (int i = 0; i < s.size(); ++i) {
        a[i] = C(1.0*(s[i]-'A'));
        b[n-1-i] = 1.0-a[i];
    }
    F(a);
    F(b);
    for (int i = 0; i < n; ++i)a[i] *= b[i];
    F(a, 1);
    for (int i = n-2;i>n-1-s.size(); --i) {
        cout << ll(real(a[i] / (double)n)+.5) << endl;
    }
}
