#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int ansi = 0;
    int ansc = 0;
    for (int i = 0; i < n; ++i) {
        string expect;
        int cnt = 0;
        for (int f = 1; f <= m; ++f) {
            if (f % 15 == 0) {
                expect = "fizzbuzz";
            } else if (f % 5 == 0) {
                expect = "buzz";
            } else if (f % 3 == 0) {
                expect = "fizz";
            } else {
                expect = to_string(f);
            }
            string got;
            cin >> got;
            if (expect == got)++cnt;
        }
        if (cnt>ansc) {
            ansc=cnt;
            ansi=i;
        }
    }
    cout << ansi+1 << endl;
}
