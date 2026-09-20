#include <bits/stdc++.h>
using namespace std;

int main() {
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int ans = INT_MAX;
    for (int ac = 0; ac <= min(a,c); ++ac) {
        for (int ad = 0; ad <= min(a-ac, d); ++ad) {
            for (int bc = 0; bc <= min(b, c-ac); ++bc) {
                for (int bd = 0; bd <= min(b-bc, d-ad); ++bd) {
                    int rem_a = a - ac - ad;
                    int rem_b = b - bc - bd;
                    int rem_c = c - ac - bc;
                    int rem_d = d - ad - bd;

                    int cur = ac * 2 + ad + bc;

                    rem_a = rem_a & 1;
                    rem_c = rem_c & 1;

                    if (rem_a > 0 && rem_b > 0) {
                        ++cur;
                        --rem_a;
                        --rem_b;
                    }
                    if (rem_c > 0 && rem_d > 0) {
                        ++cur;
                        --rem_c;
                        --rem_d;
                    }

                    cur += rem_a + rem_b + rem_c + rem_d;

                    ans = min(ans, cur);
                }
            }
        }
    }
    cout << ans << endl;
}
