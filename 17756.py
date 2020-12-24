import sys


sys.stdin.readline()
notes = [int(x) for x in sys.stdin.readline().split()]
total = sum(notes)
minimum_odd = min(note if note % 2 == 1 else 10000000001 for note in notes)
if total % 2 == 1:
    total -= minimum_odd
if total:
    print(total)
else:
    print("NIESTETY")
