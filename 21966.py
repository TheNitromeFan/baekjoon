import sys


n = int(sys.stdin.readline())
s = sys.stdin.readline().rstrip()
if n <= 25:
    print(s)
elif "." not in s[11:-12]:
    print(s[:11] + "..." + s[-11:])
else:
    print(s[:9] + "......" + s[-10:])
