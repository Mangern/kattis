prv=[]

def on_change(lst):
    genders=set(x[-1] for x in lst)
    team=lst[0][0]
    if len(lst) > 1 and len(genders) == 1:
        print(team)
        exit()

n=int(input())
a=[input() for _ in range(n)]

for s in a:
    if not prv:
        prv.append(s)
        continue
    team=s[0]
    if team != prv[0][0]:
        on_change(prv)
        prv = []
        prv.append(s)
        continue
    if len(prv) == 3 or s[1] == prv[-1][1]:
        print(team)
        exit()
    prv.append(s)

on_change(prv)
print("No violation")
