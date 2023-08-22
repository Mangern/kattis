MOD = 1000000007 
CMP = 10000000

def getfrom(x,v):
    return ((x - v)%MOD + MOD)%MOD
v = int(input())

astr = "a"

v = (v * 31 + ord(astr))%MOD
v = (v * 7) % MOD


a = 0
for i in range(1,10):
    a = getfrom(i*CMP, v)
    if a < 10**9:
        break

v = (v + a)%MOD

#print(v)

bstr = "b"

v = (v * 31 + ord(bstr))%MOD
v = (v * 7) % MOD


b = 0
for i in range(1,10):
    b = getfrom(i*CMP, v)
    if b < 10**9:
        break


v = (v + b)%MOD

print(astr, a)
print(bstr, b)
