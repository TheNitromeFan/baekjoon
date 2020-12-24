import sys
import datetime


def next_palindrome_date(day, month, year):
    date0 = datetime.datetime(year=year, month=month, day=day)
    while True:
        day = year % 10 * 10 + year // 10 % 10
        month = year // 100 % 10 * 10 + year // 1000
        try:
            date1 = datetime.datetime(year=year, month=month, day=day)
            if date1 > date0:
                return day, month, year
        except ValueError:
            pass
        year += 1


def main():
    n = int(sys.stdin.readline())
    for _ in range(n):
        d, m, y = (int(x) for x in sys.stdin.readline().rstrip()[:-1].split("."))
        day, month, year = next_palindrome_date(d, m, y)
        sys.stdout.write("{0:02d}.{1:02d}.{2:04d}.\n".format(day, month, year))


main()
