import datetime

day, mon = input().split()
day = int(day)
mon = ["JAN", "FEB", "MAR", "APR", "MAY", "JUN", "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"].index(mon)+1

cur = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"].index(input())

leap = datetime.date(2020, mon, day).weekday()

if mon == 2 and day == 29:
    base = datetime.date(2020, 1, 1).weekday()
    leap = (leap + cur - base) % 7
    if leap == 4:
        print("TGIF")
    else:
        print(":(")#)
else:
    base = datetime.date(2021, 1, 1).weekday()
    norm = datetime.date(2021, mon, day).weekday()

    leap = (leap + 2) % 7

    leap = (leap + cur - base) % 7
    norm = (norm + cur - base) % 7

    if leap == 4 and norm == 4:
        print("TGIF")
    elif leap == 4 or norm == 4:
        print("not sure")
    else:
        print(":(")#)
