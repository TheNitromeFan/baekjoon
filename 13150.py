import sys


a11, a12 = (int(x) for x in sys.stdin.readline().split())
a21, a22 = (int(x) for x in sys.stdin.readline().split())
message = ""
while (a11, a12, a21, a22) != (1, 0, 0, 1):
    if a11 >= a12 and a21 >= a22:
        message = "0" + message
        a11 -= a12
        a21 -= a22
    else:
        message = "1" + message
        a12 -= a11
        a22 -= a21
print(message)
