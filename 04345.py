import sys


time_zones = {"UTC": 0, "GMT": 0, "BST": 1, "IST": 1, "WET": 0, "WEST": 1, "CET": 1, "CEST": 2, "EET": 2, "EEST": 3,
              "MSK": 3, "MSD": 4, "AST": -4, "ADT": -3, "NST": -3.5, "NDT": -2.5, "EST": -5, "EDT": -4, "CST": -6,
              "CDT": -5, "MST": -7, "MDT": -6, "PST": -8, "PDT": -7, "HST": -10, "AKST": -9, "AKDT": -8, "AEST": 10,
              "AEDT": 11, "ACST": 9.5, "ACDT": 10.5, "AWST": 8}
n = int(sys.stdin.readline())
for _ in range(n):
    entries = sys.stdin.readline().rstrip().split()
    if len(entries) == 3:
        if entries[0] == "noon":
            hour, minute = 12, 0
        else:
            hour, minute = 0, 0
    else:
        hour, minute = (int(x) for x in entries[0].split(":"))
        if hour == 12:
            hour = 0
        if entries[1] == "p.m.":
            hour += 12
    timedelta = time_zones[entries[-1]] - time_zones[entries[-2]]
    hourdelta = int(timedelta)
    minutedelta = int(60 * (timedelta - hourdelta))
    hour += hourdelta
    minute += minutedelta
    if minute < 0:
        minute += 60
        hour -= 1
    if minute >= 60:
        minute -= 60
        hour += 1
    if hour < 0:
        hour += 24
    if hour >= 24:
        hour -= 24
    if hour == 12 and minute == 0:
        print("noon")
    elif hour == 0 and minute == 0:
        print("midnight")
    else:
        signature = "a.m."
        if hour >= 12:
            signature = "p.m."
            hour -= 12
        if hour == 0:
            hour = 12
        print(f"{hour}:{minute:02d} {signature}")