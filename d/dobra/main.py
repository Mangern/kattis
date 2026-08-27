def chng(x):
    if x == 95:
        return x
    if x == 76:
        return 2
    return 0 if x in [65, 69, 73, 79, 85] else 1

s = [chng(x) for x in map(ord, input())]

def count(i, sL = 0):
    if i == len(s):
        return 1 if sL else 0
    if s[i] != 95:
        if i >= 2 and (all((s[i-2],s[i-1],s[i])) or 
                       not any((s[i-2],s[i-1],s[i]))):
            return 0
        return count(i+1, int(sL or (s[i] == 2)))
    ret = 0
    for j in [0,1,2]:
        mul = 5 if j == 0 else (1 if j == 2 else 20)
        if i < 2:
            sv = s[i]
            s[i] = j
            ret += mul * count(i+1, int((j == 2) or sL))
            s[i] = sv
        elif (all((s[i-2],s[i-1],j)) or 
              not any((s[i-2],s[i-1],j))):
            continue
        else:
            sv = s[i]
            s[i] = j
            ret += mul * count(i+1, int((j == 2) or sL))
            s[i] = sv
    return ret


print(count(0))
