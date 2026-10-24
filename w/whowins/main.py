def hand_val(hand):
    aces = 0
    value = 0
    for h in hand:
        if h == "A":
            aces += 1
        elif h in "JQK":
            value += 10
        else:
            value += int(h)

    value += aces * 11
    while aces > 0 and value > 21:
        value -= 10
        aces -= 1
    return value

input()
d = hand_val(input().split())
input()
p = hand_val(input().split())

if d > 21 and p > 21:
    print("Push")
elif p > 21:
    print("Dealer")
elif d > 21:
    print("Player")
elif d > p:
    print("Dealer")
elif p > d:
    print("Player")
else:
    print("Push")
