def dates(line):
    if "." in line:
        day, month, year = (int(x) for x in line.split("."))
    else:
        month, day, year = (int(x) for x in line.split("/"))
    return "{0:02d}.{1:02d}.{2:04d} {1:02d}/{0:02d}/{2:04d}".format(day, month, year)


def main():
    n = int(input())
    for _ in range(n):
        date = input()
        print(dates(date))


main()
