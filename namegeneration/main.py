from itertools import product,repeat

alphabet = list(map(lambda c: chr(c+ord('a')),range(26)))
vowels = ['a','e','i','o','u']

def valid(s):
    l = list(s)
    for t in zip(l,l[1:],l[2:]):
        if all(x in vowels for x in t):
            return False
        if all(x not in vowels for x in t):
            return False
    return True

def gen():
    for l in range(3,21):
        for s in product(alphabet,repeat=l):
            if not valid(s):
                continue
            yield "".join(s)


n = int(input())

for x,_ in zip(gen(),repeat(0,n)):
    print(x)
