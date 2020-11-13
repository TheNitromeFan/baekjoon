import math


while True:
    line = input()
    if line == "END":
        break
    elif line == "1":
        print(1)
        continue
    n = len(line)
    i = 2
    while n > 1:
        i += 1
        n = int(math.log10(n)) + 1
    print(i)
