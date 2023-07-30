input(); a = list(map(int,input().split()))

a = list(filter(lambda x: x >= 0, a))
print(f"{sum(a)/len(a):.9f}")
