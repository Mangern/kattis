n=int(input())
n+=1
while True:
    if "6" not in f"{n*n}":
        print(n)
        exit()
    n += 1
