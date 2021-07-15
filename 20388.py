import sys


table = {"A": "", "E": "", "I": "", "O": "", "U": "", "Y": "", "W": "", "H": "",
         "B": "1", "P": "1", "F": "1", "V": "1",
         "C": "2", "S": "2", "K": "2", "G": "2", "J": "2", "Q": "2", "X": "2", "Z": "2",
         "D": "3", "T": "3",
         "L": "4",
         "M": "5", "N": "5",
         "R": "6"}
sys.stdout.write("         NAME                     SOUNDEX CODE\n")
for line in sys.stdin.readlines():
    name = line.rstrip()
    soundex = ""
    for i, c in enumerate(name):
        if i == 0:
            soundex += c
        elif table[c] != table[name[i - 1]]:
            soundex += table[c]
    if len(soundex) < 4:
        soundex += "0" * (4 - len(soundex))
    elif len(soundex) > 4:
        soundex = soundex[:4]
    sys.stdout.write(f"         {name.ljust(25, ' ')}{soundex}\n")
sys.stdout.write("                   END OF OUTPUT\n")
