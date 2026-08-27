#include <iostream>
#include <queue>
#include <utility>

using namespace std;
using ii = pair<int,int>;

void solve() {
    int n;
    cin >> n;

    priority_queue<ii, vector<ii>, greater<ii>> ask;
    priority_queue<ii> bid;


    int sp = -1;
    for (int i = 0; i < n; ++i) {
        string ord;
        cin >> ord;
        int cnt, price;
        cin >> cnt;
        string tm;
        cin >> tm >> tm;
        cin >> price;

        if (ord == "buy") {
            bid.push({price, cnt});
        } else {
            ask.push({price, cnt});
        }

        while (ask.size() && bid.size() && ask.top().first <= bid.top().first) {
            auto [sell, scnt] = ask.top();
            ask.pop();
            auto [buy, bcnt] = bid.top();
            bid.pop();

            int cnt = min(scnt, bcnt);
            sp = sell;
            scnt -= cnt;
            bcnt -= cnt;
            if (scnt)ask.push({sell, scnt});
            if (bcnt)bid.push({buy, bcnt});
        }

        //...
        int ap = -1;
        int bp = -1;

        if (ask.size())ap = ask.top().first;
        if (bid.size())bp = bid.top().first;

        if (ap < 0)cout << '-';
        else cout << ap;
        cout << " ";
        if (bp < 0)cout << '-';
        else cout << bp;
        cout << " ";
        if (sp < 0)cout << '-';
        else cout << sp;
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    while (t-->0)solve();
}
