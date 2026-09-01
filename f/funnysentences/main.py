a=int(input())
b=int(input())
m=int(input())
n=1
def gen():
    global a
    global b
    global n
    global m
    n = (a * n + b) % m
    return n
sub=[input() for _ in range(m)]
ver=[input() for _ in range(m)]
obj=[input() for _ in range(m)]
pla=[input() for _ in range(m)]

for _ in range(m):
    print(f"{sub[gen()]} {ver[gen()]} {obj[gen()]} {pla[gen()]}.")
