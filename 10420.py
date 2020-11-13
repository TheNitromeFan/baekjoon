from datetime import datetime, timedelta


date_1 = datetime.strptime("14/04/01", "%y/%m/%d")
n = int(input())
print("20" + (date_1 + timedelta(days=n)).strftime("%y-%m-%d"))
