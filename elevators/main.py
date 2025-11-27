mp={
    "residential":[(1,1),(2,5),(6,10),(11,15),(16,20)],
    "commercial":[(1,1),(2,7),(8,14),(15,20)],
    "industrial":[(1,1),(2,4),(5,8),(9,12),(13,16),(17,20)]
}
s,x=input().split()
l=mp[s]
x=int(x)
for i, (l,r) in enumerate(l):
    if l <= x <= r:
        print(i)
        break
