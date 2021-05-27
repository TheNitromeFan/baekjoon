import sys


while True:
    a0, length = (int(x) for x in sys.stdin.readline().split())
    if a0 == length == 0:
        break
    seen = {a0: 0}
    i = 0
    while True:
        b = str(a0).rjust(length, "0")
        maximum = int("".join(sorted(b, reverse=True)))
        minimum = int("".join(sorted(b)))
        a0 = maximum - minimum
        i += 1
        if a0 in seen:
            print(f"{seen[a0]} {a0} {i - seen[a0]}")
            break
        seen[a0] = i
