s=input()
for a in range(10):
    for b in range(10):
        for c in range(10):
            for d in range(10):
                for e in range(10):
                    if len(set([a,b,c,d,e])) != 5:
                        continue
                    t=(s.replace("a",chr(ord('0')+a))
                        .replace("b",chr(ord('0')+b))
                        .replace("c",chr(ord('0')+c))
                        .replace("d",chr(ord('0')+d))
                        .replace("e",chr(ord('0')+e)))
                    lhs,rhs=t.split("=")
                    x,y=lhs.split("+")
                    if int(x)+int(y)==int(rhs):
                        print(f"{a}{b}{c}{d}{e}")
                        exit()
print("impossible")
