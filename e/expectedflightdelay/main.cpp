#include <bits/stdc++.h>
using namespace std;

int prv(int d) {
    --d;
    if (d < 0) d = 6;
    return d;
}

int main() {
    vector<string> day_names = {
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday",
        "Friday",
        "Saturday",
        "Sunday"
    };

    int meetday;
    cin >> meetday, --meetday;
    meetday = prv(meetday);
    double pwday, pwend;
    double p_imp;
    cin >> pwday >> pwend >> p_imp;
    pwday /= 100.0;
    pwend /= 100.0;
    p_imp /= 100.0;
    double p_prev = 0.0;
    int wd = prv(meetday);
    for (int i = 1; ; ++i) {
        double p_ok = (wd >= 5 ? pwend : pwday);

        double p_here = p_ok + (1.0 - p_ok) * p_prev;

        if (p_here >= p_imp) {
            cout << "Try to leave on " << day_names[wd] << ", " << i << " day" << (i > 1 ? "s" : "") << " before the " << day_names[meetday] << " meeting." << endl;
            return 0;
        }

        p_prev = p_here;
        wd = prv(wd);
    }
}
