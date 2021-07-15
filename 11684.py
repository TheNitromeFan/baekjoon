import sys


a, b = (int(x) for x in sys.stdin.readline().split())
seen = set()
for i in range(1, 65):
    for j in range(1, 65):
        s = ""
        while True:
            s += "1" * i
            x = int(s, base=2)
            if a <= x <= b and x not in seen:
                seen.add(x)
            elif x > b:
                break
            s += "0" * j
            x = int(s, base=2)
            if a <= x <= b and x not in seen:
                seen.add(x)
            elif x > b:
                break
print(len(seen))
