notes=["A", "A#", "B","C","C#","D","D#","E","F","F#","G","G#"]
n1,n2,n3=map(lambda x: int(x)%12, input().split())
for base in [n1,n2,n3]:
    i1=base
    i2=(base+4)%12
    i3=(i2+3)%12

    if sorted([n1,n2,n3]) == sorted([i1,i2,i3]):
        print(f"{notes[base]} major")
        exit()

    i1=base
    i2=(base+3)%12
    i3=(base+7)%12
    if sorted([n1,n2,n3]) == sorted([i1,i2,i3]):
        print(f"{notes[base]} minor")
        exit()
print("neither")
