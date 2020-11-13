while True:
    a, b, c, d = (int(x) for x in input().split())
    if a == b == c == d == 0:
        break
    ans = 0
    while not a == b == c == d:
        ans += 1
        a, b, c, d = abs(a - b), abs(b - c), abs(c - d), abs(d - a)
    print(ans)
