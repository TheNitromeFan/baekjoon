n, m = (int(x) for x in input().split())
if m in [1, 2]:
    print("NEWBIE!")
elif m <= n:
    print("OLDBIE!")
else:
    print("TLE!")
