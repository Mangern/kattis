n=int(input())

if n % 4 != 0 or (n % 100 == 0 and n % 400 != 0):
    print("Neibb")
    exit()

n100 = n // 100 - 2020 // 100 
n400 = n // 400 - 2020 // 400
n4   = n // 4 - 2020 // 4

print(n4-n100+n400)
