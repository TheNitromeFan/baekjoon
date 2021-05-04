import sys
import itertools
import datetime


values = [int(x) for x in sys.stdin.readline().split("/")]
dates = set()
for a, b, c in itertools.permutations(values):
    try:
        if a == 0:
            d = datetime.date(year=2100, month=b, day=c)
        else:
            d = datetime.date(year=2000+a, month=b, day=c)
        dates.add((a, b, c))
    except ValueError:
        continue
if dates:
    for a, b, c in dates:
        sys.stdout.write(f"{c:02d}/{b:02d}/{a:02d}\n")
else:
    sys.stdout.write("No such date\n")
