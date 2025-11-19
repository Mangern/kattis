#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int ss = 0, sm = 0, sl = 0;
    for (int i = 0; i < n; ++i) {
        char c; 
        int x;

        cin >> c >> x;

        switch(c) {
            case 'S':
                ss += x;
                break;
            case 'M':
                sm += x;
                break;
            case 'L':
                sl += x;
                break;
        }
    }

    cout << ((ss+5)/6 + (sm+7)/8 + (sl+11)/12) << endl;
}
