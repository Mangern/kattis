#include <iostream>
#include <stack>

using namespace std;

const int mxN = 2e5+5;

int n;
int a[mxN];

int main() {
    cin >> n;

    for (int i = 0; i < 2*n; ++i)cin >> a[i];

    stack<int> stk;
    stack<int> aux;

    for (int i = 2 * n - 1; i >= 0; --i)stk.push(a[i]);


    int ans = 0;
    while (stk.size()) {
        ++ans;
        if (aux.size() && aux.top() == stk.top()) {
            aux.pop();
            stk.pop();
        } else {
            aux.push(stk.top());
            stk.pop();
        }
    }

    if (aux.empty()) {
        cout << ans << endl;
    } else cout << "impossible" << endl;
}
