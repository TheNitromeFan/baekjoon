import sys


for line in sys.stdin.readlines():
    line = line.rstrip()
    for i in range(0, len(line), 2):
        print(chr(int(line[i:i + 2], base=16)), end="")
    print()
