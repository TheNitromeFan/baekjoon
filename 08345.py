import sys


rows = ["`1234567890-=", "QWERTYUIOP[]\\", "ASDFGHJKL;'", "ZXCVBNM,./", " "]
s = sys.stdin.readline()
for c in s:
    for idx, row in enumerate(rows, start=1):
        if c in row:
            print(idx, end="")
            break
