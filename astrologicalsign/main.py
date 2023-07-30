sign = [
    ("Aries", (3,21), (4,20)),
    ("Taurus", (4,21), (5,20)),
    ("Gemini", (5,21), (6,21)),
    ("Cancer", (6,22), (7,22)),
    ("Leo", (7,23), (8,22)),
    ("Virgo", (8,23), (9,21)),
    ("Libra", (9,22), (10,22)),
    ("Scorpio", (10,23), (11,22)),
    ("Sagittarius", (11,23), (12,21)),
    ("Capricorn", (12,22), (1,20)),
    ("Aquarius", (1,21), (2,19)),
    ("Pisces", (2,20), (3,20))
]

month = {
    "Jan": 1,
    "Feb": 2,
    "Mar": 3,
    "Apr": 4,
    "May": 5,
    "Jun": 6,
    "Jul": 7,
    "Aug": 8,
    "Sep": 9,
    "Oct":10,
    "Nov":11,
    "Dec":12
}

for _ in range(int(input())):
    d,m=input().split()
    d=int(d)
    m = month[m]

    for sig, start,end in sign:
        if m == start[0] and d >= start[1] or m == end[0] and d <= end[1]:
            print(sig)
