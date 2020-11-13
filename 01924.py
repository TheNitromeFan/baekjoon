weekdays = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]


def weekday(month, day):
    days = sum(months[:month-1]) + day-1
    return weekdays[days % 7]


print(weekday(*(int(a) for a in input().split())))
