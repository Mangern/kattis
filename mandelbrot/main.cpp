#include <bits/stdc++.h>
using namespace std;
using ld = long double;

int main() {
    ld x, y;
    int r;
    int tc=1;
    while (cin >> x) {
        cin >> y >> r;

        complex<ld> c{x,y};
        complex<ld> z=0.0;

        bool div=0;
        for (int i = 0; i <= r; ++i) {
            if (z.real()*z.real()+z.imag()*z.imag() > 4.0) {
                div=1;
                break;
            }
            z = z * z + c;

        }
        cout << "Case " << tc << ": " << (div ? "OUT" : "IN") << '\n';
        ++tc;
    }
}
