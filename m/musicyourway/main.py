attrs = input().split()
n = int(input())

songs = [tuple(input().split()) for _ in range(n)]

for i in range(int(input())):
    attr = input()
    i_a = attrs.index(attr)
    songs.sort(key=lambda t: t[i_a])
    print(" ".join(attrs))
    print("\n".join(" ".join(s) for s in songs))
    print()
