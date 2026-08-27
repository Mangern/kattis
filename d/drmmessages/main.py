from functools import reduce
s = input()
a = s[:len(s)//2]
b = s[len(s)//2:]
fst = reduce(lambda x,y:x+ord(y)-ord("A"),a, 0)
lst = reduce(lambda x,y:x+ord(y)-ord("A"),b, 0)
a = "".join(map(lambda c: chr((ord(c)-ord("A")+fst)%26+ord("A")),a))
b = "".join(map(lambda c: chr((ord(c)-ord("A")+lst)%26+ord("A")),b))
print("".join(map(lambda tup: chr((ord(tup[0])+ord(tup[1])-2*ord("A"))%26+ord("A")), zip(a,b))))
