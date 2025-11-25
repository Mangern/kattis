s=input()
a=""
i = 1
while True:
    a += f"{i}"
    if a == s:
        print(i)
        exit()
    elif len(a)>len(s):
        break
    i += 1
print(-1)
