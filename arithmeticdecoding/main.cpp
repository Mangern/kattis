#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    double d;
    cin >> d;

    double pa = d /8;

    string enc;
    cin >> enc;

    double enc_val = 0.0;

    double mul = 0.5;
    for (int i = 2; i < enc.length(); ++i) {
        if (enc[i] == '1')enc_val += mul;
        mul *= 0.5;
    }

    int mask;
    for (mask = 0; mask < (1<<n); ++mask) {
        double a = 0;
        double b = 1;

        for (int i = 0; i < n; ++i) {
            double c = a + pa * (b - a);
            if (mask & (1<<i)) {
                // A
                b = c;
            } else {
                a = c;
            }
        }

        if (a == enc_val) {
            break;
        }
    }

    string ans;
    for (int i = 0; i < n; ++i) {
        if (mask & (1<<i))ans.push_back('A');
        else ans.push_back('B');
    }
    cout << ans << endl;

    return 0;
}
