a, b, n = (int(x) for x in input().split())
a %= b
for _ in range(n):
    q, r = divmod(a * 10, b)
    a = r
print(q)
