import datetime


y1, m1, d1 = (int(x) for x in input().split())
y2, m2, d2 = (int(x) for x in input().split())
date1 = datetime.date(y1, m1, d1)
date2 = datetime.date(y2, m2, d2)
date3 = datetime.date(y1 + 1000, m1, d1)
dday = (date2 - date1).days
limit = (date3 - date1).days
if dday >= limit:
    print("gg")
else:
    print("D-{}".format(dday))
