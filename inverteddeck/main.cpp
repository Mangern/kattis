#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto& x : a)cin >> x;

    int l = 0;
    int r = n;

    int cntr = 0;
    while (l < n - 1 && a[l] <= a[l+1])++l;

    //cout << l << endl;

    if (l == n - 1) {
        cout << "1 1" << endl;
        return 0;
    }

    int s = l;

    while (l > 0 && a[l-1] == a[s])--l;

    while (a[r-1] >= a[l])--r;

    //cout << r << endl;

    reverse(begin(a)+l, begin(a)+r);

    //for (auto x : a)cout << x << " ";
    //cout << endl;


    for (int i = 1; i < n; ++i)if (a[i] < a[i-1]) {
        cout << "impossible" << endl;
        return 0;
    }

    cout << l+1 << " " << r << endl;
    

    return 0;
}
