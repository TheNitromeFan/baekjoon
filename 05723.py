import sys
import datetime


def read(readings, n):
    cnt, ans = 0, 0
    for i in range(1, n):
        dj, cj = readings[i - 1]
        di, ci = readings[i]
        if dj + datetime.timedelta(days=1) == di:
            cnt += 1
            ans += ci - cj
    return cnt, ans


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        readings = []
        for _ in range(n):
            d, m, y, c = (int(x) for x in sys.stdin.readline().split())
            readings.append((datetime.datetime(year=y, month=m, day=d), c))
        cnt, ans = read(readings, n)
        print(cnt, ans)


main()
