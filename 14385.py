import sys


sys.stdout.write("Case #1:\n")
for i in range(50):
    s = "11"
    for j in range(6):
        if i & (1 << j):
            s += "11"
        else:
            s += "00"
    s += "11"
    sys.stdout.write(s)
    for k in range(2, 11):
        sys.stdout.write(f" {k + 1}")
    sys.stdout.write("\n")
