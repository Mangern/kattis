from itertools import chain
fl = []
sl = []
while True:
    try:
        s = input()
        a,b=s.strip().split("|")
        fl.append(a)
        sl.append(b)
    except:
        break

print("".join(chain(fl,[" "], sl)))
