import sys
import datetime


def gender(pid):
    if pid.count("/") != 1:
        return "invalid"
    date, check = pid.split("/")
    if not (len(date) == 6 and len(check) in [3, 4]):
        return "invalid"
    year, month, day = int(date[:2]), int(date[2:4]), int(date[4:])
    if 10 <= year < 20:
        return "invalid"
    ret = "boy"
    if month <= 50:
        try:
            date1 = datetime.datetime(year=year + 2000, month=month, day=day)
        except ValueError:
            return "invalid"
    else:
        ret = "girl"
        try:
            date2 = datetime.datetime(year=year + 2000, month=month - 50, day=day)
        except ValueError:
            return "invalid"
    if 20 <= year <= 53:
        if len(check) != 3:
            return "invalid"
    else:
        if len(check) != 4:
            return "invalid"
        if int(date + check) % 11 != 0:
            return "invalid"
    return ret


def main():
    while True:
        pid = sys.stdin.readline().rstrip()
        if pid == "end":
            break
        sys.stdout.write(gender(pid) + "\n")


main()
