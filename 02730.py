import sys
import datetime


def bank():
    entries = sys.stdin.readline().rstrip().split()
    date1 = datetime.datetime.strptime(entries[0], "%m/%d/%Y")
    year1 = int(entries[0].split("/")[-1])
    for year in [year1 - 1, year1, year1 + 1]:
        try:
            date2 = datetime.datetime.strptime(entries[1] + "/{}".format(year), "%m/%d/%Y")
        except ValueError:
            continue
        if date1 == date2:
            return "SAME DAY\n"
        elif date2 - date1 == datetime.timedelta(days=1):
            return "{}/{}/{} IS {} DAY AFTER\n".format(date2.month, date2.day, date2.year, (date2 - date1).days)
        elif datetime.timedelta(days=0) <= date2 - date1 <= datetime.timedelta(days=7):
            return "{}/{}/{} IS {} DAYS AFTER\n".format(date2.month, date2.day, date2.year, (date2 - date1).days)
        elif date1 - date2 == datetime.timedelta(days=1):
            return "{}/{}/{} IS {} DAY PRIOR\n".format(date2.month, date2.day, date2.year, (date1 - date2).days)
        elif datetime.timedelta(days=0) <= date1 - date2 <= datetime.timedelta(days=7):
            return "{}/{}/{} IS {} DAYS PRIOR\n".format(date2.month, date2.day, date2.year, (date1 - date2).days)
    return "OUT OF RANGE\n"


def main():
    x = int(sys.stdin.readline())
    for _ in range(x):
        sys.stdout.write(bank())


main()
