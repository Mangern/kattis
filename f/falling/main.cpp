#include <cmath>
#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll d;
  cin >> d;

  if (d % 4 == 2) {
      cout << "impossible" << endl;
      return 0;
  }

  for (ll b = 0;; ++b) {
    ll a = sqrtl(d + b * b);

    if (a * a == d + b * b) {
      cout << b << " " << a << endl;
      return 0;
    }
    if ((a + 1) * (a + 1) == d + b * b) {
      cout << b << " " << a + 1 << endl;
      return 0;
    }
  }
  return 0;
}
