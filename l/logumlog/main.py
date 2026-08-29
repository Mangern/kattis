notes={
    "C": 0,
    "C#": 1, "Db": 1,
    "D": 2,
    "D#": 3, "Eb": 3,
    "E": 4,
    "F": 5,
    "F#": 6, "Gb": 6,
    "G": 7,
    "G#": 8, "Ab": 8,
    "A": 9,
    "A#": 10, "Bb": 10,
    "B": 11,
}

def get_note_val(note):
    global notes
    if note in notes:
        return notes[note]
    assert note[-1] == '#' or note[-1] == 'b'
    base = note[0]
    prog = "CDEFGAB"
    if note[-1] == '#':
        return notes[prog[(prog.index(base)+1)%len(prog)]]
    else:
        return notes[prog[(prog.index(base)-1)%len(prog)]]

def get_val(full_note):
    if full_note == "-":
        return None
    octave=int(full_note[-1])
    note=get_note_val(full_note[:-1])
    if full_note.startswith("Cb"):
        octave -= 1
    if full_note.startswith("B#"):
        octave += 1
    return octave * 12 + note

n=int(input())
song1=list(map(get_val, input().split()))
song2=list(map(get_val, input().split()))
nonz = [x for x in song1 if x is not None]
if len(nonz):
    song1=[x if x is None else x - nonz[0] for x in song1]

nonz = [x for x in song2 if x is not None]
if len(nonz):
    song2=[x if x is None else x - nonz[0] for x in song2]

print("Jebb" if song1 == song2 else "Neibb")
