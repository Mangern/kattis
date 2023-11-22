n = int(input())

ps = None
fluck = False
for i in range(n):
    s = input()
    if s != "Present!":
        if ps is not None:
            print(ps)
            fluck = True
        ps = s
    else:
        ps = None

if ps is not None:
    print(ps)
    fluck = True

if not fluck:
    print("No Absences")
