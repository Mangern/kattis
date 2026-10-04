#include <bits/stdc++.h>
using namespace std;

int main()
{
    int xs, ys, xt, yt;
    cin >> xs >> ys >> xt>>yt;

    xt-= xs;
    yt -= ys;
    int a = min(abs(xt), abs(yt));

    if (xt > 0 && yt > 0)
    {
        cout << "NE\n";
        xt -= a;
        yt -= a;
    }
    if (xt < 0 && yt > 0)
    {
        cout << "NW\n";
        yt -= a;
        xt += a;
    }

    if (xt > 0 && yt < 0)
    {
        cout << "SE\n";
        xt -= a;
        yt += a;
    }

    if (xt < 0 && yt <0 )
    {
        cout << "SW\n";
        xt += a;
        yt += a;
    }

    if (xt < 0)
    {
        cout << "W\n";
    } 
    if (xt > 0)
    {
        cout << "E\n";
    }

    if (yt < 0)
    {
        cout << "S\n";
    }

    if (yt > 0)
    {
        cout << "N\n";
    }
}