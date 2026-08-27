#include <bits/stdc++.h>
#include <cstdlib>
#include <iomanip>
using namespace std;
using ld = long double;

int main() {
    ld n;
    cin >> n;

    ld lo = 1;
    ld hi = 10;

    const ld PREC = 1e-8;


    while (hi - lo > PREC) {
        ld x = (lo+hi) / 2.0;
        
        ld res = pow(x, x);

        if (res < n) {
            lo = x;
        } else {
            hi = x;
        }
    }

    cout << setprecision(6) << fixed << lo << endl;

    return 0;
}
