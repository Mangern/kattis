def yes():
    print("yes")
    exit()

card1, card2 = input().split()

ranks="__23456789TJQKA"

r1 = ranks.index(card1[0])
r2 = ranks.index(card2[0])
s1 = card1[1]
s2 = card2[1]

if r1 == r2 and r1 > 3:
    yes()

if min(r1, r2) + 1 == max(r1, r2) and min(r1, r2) >= 9:
    yes()

if s1 == s2 and max(r1, r2) >= 12:
    yes()

if min(r1, r2) >= 11:
    yes()

print("no")
