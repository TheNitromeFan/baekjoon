import sys


def main():
    notes = {"W": 64, "H": 32, "Q": 16, "E": 8, "S": 4, "T": 2, "X": 1}
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "*":
            break
        measures = line[1:-1].split("/")
        cnt = 0
        for measure in measures:
            if sum(notes[note] for note in measure) == 64:
                cnt += 1
        print(cnt)


main()
