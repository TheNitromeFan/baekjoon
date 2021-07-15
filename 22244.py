import sys
import datetime


def is_good_catalog_number(catalog):
    day, month, year, author, control \
        = int(catalog[:2]), int(catalog[2:4]), int(catalog[4:7]), int(catalog[7]), int(catalog[8])
    if year <= 599:
        year += 2000
    else:
        year += 1000
    try:
        datetime.datetime(year=year, month=month, day=day)
    except ValueError:
        return False
    if author not in [1, 6, 9]:
        return False
    checksum = 0
    for i in range(8):
        checksum += int(catalog[i]) ** 2
    return checksum % 7 == control


def main():
    for _ in range(3):
        catalog = sys.stdin.readline().rstrip()
        print(int(is_good_catalog_number(catalog)))


main()
