#include "countingdays.h"

int ch = 0;
int cm = 0;
int cd = 1;

void lookAtClock(int hours, int minutes) {
    if (!(hours > ch || (hours == ch && minutes > cm))) {
        ++cd;
    }
    ch = hours;
    cm = minutes;
}

int getDay() {
    return cd;
}

