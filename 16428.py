a, b = (int(x) for x in input().split())
if a > 0 and b > 0:
    q, r = a // b, a % b
elif b > 0:
    q, r = -(-a // b), -(-a % b)
    if r:
        q -= 1
        r += b
elif a > 0:
    q, r = -(a // -b), a % -b
else:
    q, r = -a // -b, -a % -b
    if r:
        q += 1
        r = -b - r
print(str(q))
print(str(r))
