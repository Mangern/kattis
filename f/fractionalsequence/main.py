from math import gcd
n=int(input())

i = 1
while True:
    if i >= n:
        break
    n -= i
    i += 1

top=i * i + n - 1
bot=i
w=top//bot
top=top%bot
if top==0:
    print(w)
    exit()
g=gcd(top,bot)
top//=g
bot//=g
print(f"{w} {top}/{bot}")
