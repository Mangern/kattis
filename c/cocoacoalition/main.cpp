#include <iostream>
using namespace std;
using ll = long long;

int main() {
    ll n, m, a;
    cin >> n >> m >> a;

    if (a % n == 0 || a % m == 0) {
        cout << 1 << endl;
        return 0;
    }

    for (int _ = 0; _ < 2; ++_) {
        for (int i = 1; i <= n; ++i) {
            if (a % i == 0 && (a / i <= m)) {
                cout << 2 << endl;
                return 0;
            }
        }
        a = n * m - a;
    }
    cout << 3 << endl;
}
