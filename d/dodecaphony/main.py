notes=["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]

n=int(input())
mel1 = list(map(notes.index, input().split()))
mel2 = list(map(notes.index, input().split()))

istrans=True
delta=mel2[0] - mel1[0]
for i in range(1, n):
    if mel2[i] - mel1[i] != delta:
        istrans=False
        break

if istrans:
    print("Transposition")
    exit()

if mel2[::-1] == mel1:
    print("Retrograde")
    exit()

isinv = True

for i in range(n):
    dif = mel1[i] - mel1[0]
    expect = (mel1[0] - dif)%len(notes)
    if mel2[i] != expect:
        isinv=False

if isinv:
    print("Inversion")
else:
    print("Nonsense")
