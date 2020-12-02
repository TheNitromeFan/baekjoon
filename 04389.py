import sys
import datetime


def merit_message(merit, demerit):
    if merit == demerit == 0:
        return "No merit or demerit points."
    elif merit == 0:
        return "{} demerit point(s).".format(demerit)
    elif demerit == 0:
        return "{} merit point(s).".format(merit)


def process(dates):
    date = datetime.datetime(year=dates[0][0] // 10000, month=dates[0][0] % 10000 // 100, day=dates[0][0] % 100)
    merit, demerit = 0, 0
    sys.stdout.write("{} {}\n".format(date.strftime("%Y-%m-%d"), merit_message(merit, demerit)))
    index = 1
    while index < len(dates):
        new_date = datetime.datetime(year=dates[index][0] // 10000,
                                     month=dates[index][0] % 10000 // 100,
                                     day=dates[index][0] % 100)
        offense = dates[index][1]
        while merit == 0 and demerit > 0 \
                and datetime.datetime(year=date.year + 1, month=date.month, day=date.day) <= new_date:
            date = datetime.datetime(year=date.year + 1, month=date.month, day=date.day)
            demerit = max(int(demerit - max(demerit / 2, 2)), 0)
            sys.stdout.write("{} {}\n".format(date.strftime("%Y-%m-%d"), merit_message(merit, demerit)))
        count = 0
        while demerit == 0 and count < 5 \
                and datetime.datetime(year=date.year + 2, month=date.month, day=date.day) <= new_date:
            date = datetime.datetime(year=date.year + 2, month=date.month, day=date.day)
            merit += 1
            count += 1
            sys.stdout.write("{} {}\n".format(date.strftime("%Y-%m-%d"), merit_message(merit, demerit)))
        if offense > 2 * merit:
            offense -= 2 * merit
            merit = 0
            demerit += offense
        else:
            merit = int(merit - offense / 2)
        date = new_date
        sys.stdout.write("{} {}\n".format(date.strftime("%Y-%m-%d"), merit_message(merit, demerit)))
        index += 1
    while merit == 0 and demerit > 0 \
            and datetime.datetime(year=date.year + 1, month=date.month, day=date.day):
        date = datetime.datetime(year=date.year + 1, month=date.month, day=date.day)
        demerit = max(int(demerit - max(demerit / 2, 2)), 0)
        sys.stdout.write("{} {}\n".format(date.strftime("%Y-%m-%d"), merit_message(merit, demerit)))
    count = 0
    while demerit == 0 and count < 5 \
            and datetime.datetime(year=date.year + 2, month=date.month, day=date.day):
        date = datetime.datetime(year=date.year + 2, month=date.month, day=date.day)
        merit += 1
        count += 1
        sys.stdout.write("{} {}\n".format(date.strftime("%Y-%m-%d"), merit_message(merit, demerit)))


def main():
    dates = []
    for line in sys.stdin.readlines():
        dates.append(tuple(int(x) for x in line.split()))
    process(dates)


main()
