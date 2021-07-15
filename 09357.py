import sys


t = int(sys.stdin.readline())
for a0 in range(1, t + 1):
    n = int(sys.stdin.readline())
    contestants = {}
    for _ in range(n):
        line = sys.stdin.readline().rstrip()
        name, year = line[:-5], int(line[-4:])
        if name not in contestants:
            contestants[name] = set()
        contestants[name].add(year)
    eligible = [key for key, val in contestants.items() if len(val) < 5]
    print(f"Case #{a0}:")
    for name in sorted(eligible):
        print(name)
