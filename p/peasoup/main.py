n =  int(input())
found = None

for i in range(n):
    k = int(input())
    name = input()
    stuff = [input() for _ in range(k)]
    if found is None and "pea soup" in stuff and "pancakes" in stuff:
        found = name

print(found if found else "Anywhere is fine I guess")
