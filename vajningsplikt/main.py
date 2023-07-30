a,b,c=[x[0] for x in input().split()]
opo={
    'N':'S',
    'E':'W',
    'S':'N',
    'W':'E'
}
rgt={
    'N':'E',
    'E':'S',
    'S':'W',
    'W':'N'
}

if opo[a] == b:
    print("Yes" if rgt[b]==c else "No")
elif rgt[a] == b:
    print("Yes" if rgt[opo[a]]==c or opo[a]==c else "No")
else:
    print("No")
