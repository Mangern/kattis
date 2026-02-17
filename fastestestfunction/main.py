a, b = map(int, input().split())
a/=100
b/=100

# Total time before: T1
# foo time before: aT1
# other code: T1 - aT1
# Total time after: T2 = other + foo after
# => T2 = (T1 - aT1) + bT2
# => T2(1-b) = (T1 - aT1)

# Want to know: aT1 / bT2
# T2(1-b) = T1(1-a)
# T1 / T2 = (1 - b) / (1 - a)
# 
# Factor = a / b * (1 - b) / (1 - a)
print(a / b * (1 - b) / (1 - a))
