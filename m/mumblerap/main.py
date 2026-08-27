import re
input()
s = input()

l = re.split('[^\d]+', s)
print(max(int(x) for x in l if x))
