#include <cstring>
#include <iostream>

using namespace std;

int a[101];
int b[101];
int mtch[101];

void match(int k) {
    int j = 100;
    memset(mtch, 0, sizeof mtch);

    int res = 0;
    for (int i = 1; i <= 100; ++i) {
        if (!a[i])continue;
        int m = 0;
        while (m < a[i]) {
            while (!(b[j] - mtch[j]))--j;
            res = max(res, i+j);
            int cur = min(a[i] - m, b[j] - mtch[j]);
            m += cur;
            mtch[j] += cur;
        }
    }

    cout << res << endl;
}

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        ++a[x];
        ++b[y];

        match(i+1);
    }
}
