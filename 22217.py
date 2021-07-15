import sys


m = int(sys.stdin.readline())
left = []
right = []
weight = 1
while m:
    if m % 3 == 1:
        right.append(weight)
        m -= 1
    elif m % 3 == 2:
        left.append(weight)
        m += 1
    m //= 3
    weight *= 3
print(f"{len(left)} {' '.join(str(x) for x in left)}")
print(f"{len(right)} {' '.join(str(x) for x in right)}")
