import sys


t = int(sys.stdin.readline())
for _ in range(t):
    hh, mm, zone = sys.stdin.readline().rstrip().split()
    a = int(hh)
    b = int(mm)
    current_time = a * 60 + b
    if "." in zone:
        x, y = (int(z) for z in zone[4:].split("."))
        time = 6 * (10 * x + y)
        if zone[3] == "-":
            time *= -1
    else:
        time = 60 * int(zone[3:])
    new_time = (current_time + (time - 8 * 60)) % (24 * 60)
    print(f"{new_time // 60:02d}:{new_time % 60:02d}")
