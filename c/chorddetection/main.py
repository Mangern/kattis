notes=["C","C#","D","D#","E","F","F#","G","G#","A", "A#", "B"]
n1=notes.index(input())
n2=notes.index(input())
n3=notes.index(input())
for base in [n1,n2,n3]:
    i1=base
    i2=(base+4)%12
    i3=(i2+3)%12

    if sorted([n1,n2,n3]) == sorted([i1,i2,i3]):
        print(f"{notes[base]} major")
        exit()
print("not a chord")
