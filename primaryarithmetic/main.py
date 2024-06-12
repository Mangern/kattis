while True:
    a, b = input().split()
    if a == "0" and b == "0":
        break

    while len(a) < len(b):
        a = "0" + a
    while len(b) < len(a):
        b = "0" + b

    cr = 0
    ans = 0
    for x, y in zip(a[::-1], b[::-1]):
        if int(x)+int(y)+cr >= 10:
            ans += 1
        cr = (int(x) + int(y) + cr) //10

    if ans == 0:
        print("No carry operation.")
    elif ans == 1:
        print("1 carry operation.")
    else:
        print(f"{ans} carry operations.")
