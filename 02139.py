from datetime import datetime, timedelta

while True:
    d, m, y = (int(x) for x in input().split())
    if d == 0 and m == 0 and y == 0:
        break
    delta = datetime(day=d, month=m, year=y) - datetime(day=1, month=1, year=y)
    print(delta.days + 1)
