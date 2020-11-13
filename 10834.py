m = int(input())
left, right, rotations = 1, 1, 0
for _ in range(m):
    a, b, r = (int(x) for x in input().split())
    left *= a
    right *= b
    rotations += r
print("{} {}".format(rotations % 2, right // left))
