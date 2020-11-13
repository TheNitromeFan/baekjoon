from datetime import datetime, timedelta


x = input().split()
date1 = datetime.strptime(x[0], "%Y-%m-%d")
n = int(x[1])
print((date1 + timedelta(days=n-1)).strftime("%Y-%m-%d"))
