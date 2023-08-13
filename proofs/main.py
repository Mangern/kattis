n = int(input())

truth = set()

for i in range(n):
    s = input().split("->")
    if s[0] == "":
        truth.add(s[1].strip())
    else:
        prem = s[0].split()
        for p in prem:
            if not p in truth:
                print(i+1)
                break
        else:
            truth.add(s[1].strip())
            continue
        break
else:
    print("correct")
