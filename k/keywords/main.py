uniq = set()
for i in range(int(input())):
    uniq.add(input().lower().replace("-", " "))
print(len(uniq))
