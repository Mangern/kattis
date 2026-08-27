#include <iostream>
using namespace std;

int solve(int n, int k) {
    if (n == 1) return 0;
    return (solve(n - 1, k) + k)%n;
}

int main() {
    int t, k;
    cin >> t >> k;

    cout << solve(t, k) << endl;
}
