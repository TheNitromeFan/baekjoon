days_in_month = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
months = {"January": 1, "February": 2, "March": 3, "April": 4, "May": 5, "June": 6, "July": 7, "August": 8,
          "September": 9, "October": 10, "November": 11, "December": 12}


def is_leap(year):
    return year % 4 == 0 and year % 100 != 0 or year % 400 == 0


def total_minutes(year):
    days = 365
    if is_leap(year):
        days = 366
    return days * 24 * 60


def minutes_so_far(year, month, day, hour, minute):
    if is_leap(year):
        days_in_month[1] = 29
    return sum(days_in_month[i] for i in range(month-1)) * 24 * 60 + (day-1) * 24 * 60 + hour * 60 + minute


def ratio(year, month, day, hour, minute):
    return minutes_so_far(year, month, day, hour, minute) / total_minutes(year)


mon, d, y, time = input().split()
h, m = time.split(":")
print(ratio(int(y), months[mon], int(d[:-1]), int(h), int(m)) * 100)
