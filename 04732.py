import sys


default_notes = ["A", "A#", "B", "C", "C#", "D", "D#", "E", "F", "F#", "G", "G#"]
non_default_notes = {"Ab": "G#", "Bb": "A#", "B#": "C", "Cb": "B", "Db": "C#", "Eb": "D#", "E#": "F", "Fb": "E", "Gb": "F#"}


while True:
    notes = sys.stdin.readline().rstrip()
    if notes == "***":
        break
    step = int(sys.stdin.readline())
    for note in notes.split():
        if note in non_default_notes:
            note = non_default_notes[note]
        # print(note)
        # print(default_notes.index(note))
        print(default_notes[(default_notes.index(note) + step) % 12], end=" ")
    print()
