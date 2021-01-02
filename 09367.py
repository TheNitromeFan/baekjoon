import sys
import math


t = int(sys.stdin.readline())
for _ in range(t):
    n, m = (int(x) for x in sys.stdin.readline().split())
    cars = {}
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        car, price, pickup, cost = entries[0], int(entries[1]), int(entries[2]), int(entries[3])
        cars[car] = (price, pickup, cost)
    logs = []
    for _ in range(m):
        entries = sys.stdin.readline().rstrip().split()
        logs.append(entries)
    logs.sort(key=lambda x: int(x[0]))
    spies = {}
    for i in range(m):
        entries = logs[i]
        time, spy, entry = int(entries[0]), entries[1], entries[2]
        if entry == "p":
            car = entries[3]
            if spy in spies and spies[spy][0] is not None:
                spies[spy][0] = "INCONSISTENT"
            elif spy in spies:
                spies[spy][0] = car
                spies[spy][1] += cars[car][1]
            else:
                spies[spy] = [car, cars[car][1]]
        elif entry == "r":
            d = int(entries[3])
            if spy in spies and (spies[spy][0] is None or spies[spy][0] == "INCONSISTENT"):
                spies[spy][0] = "INCONSISTENT"
            elif spy in spies:
                car = spies[spy][0]
                spies[spy][0] = None
                spies[spy][1] += cars[car][2] * d
            else:
                spies[spy] = ["INCONSISTENT", 0]
        else:
            severity = int(entries[3])
            if spy in spies and (spies[spy][0] is None or spies[spy][0] == "INCONSISTENT"):
                spies[spy][0] = "INCONSISTENT"
            elif spy in spies:
                car = spies[spy][0]
                spies[spy][1] += int(math.ceil(cars[car][0] * severity / 100.0))
            else:
                spies[spy] = ["INCONSISTENT", 0]
    bills = []
    for spy in spies:
        if spies[spy][0] is not None:
            bills.append((spy, "INCONSISTENT"))
        else:
            bills.append((spy, str(spies[spy][1])))
    bills.sort()
    for spy, bill in bills:
        print(spy, bill)
