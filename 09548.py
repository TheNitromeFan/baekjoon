import sys


t = int(sys.stdin.readline())
for _ in range(t):
    s = sys.stdin.readline().rstrip()
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "END":
            break
        entries = line.split()
        if entries[0] == "I":
            r, x = entries[1], int(entries[2])
            s = s[:x] + r + s[x:]
        elif entries[0] == "P":
            x, y = int(entries[1]), int(entries[2])
            print(s[x:y + 1])
