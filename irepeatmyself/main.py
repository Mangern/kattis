from itertools import cycle 

def expl(p,s):
    #print(p,s)
    for a,b in zip(s,cycle(p)):
        if a != b:
            return False
    return True

for _ in range(int(input())):
    s = input()
    for i in range(len(s)):
        if expl(s[:i+1],s):
            print(i+1)
            break

