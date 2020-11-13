import sys


def main():
    line = sys.stdin.readline().strip().split()
    n = int(line[0])
    d = float(line[1])
    for line in sys.stdin.readlines():
        line = line.strip().split()
        team = line[0]
        total_time = 0
        dq = False
        # print(line)
        for time in line[1:]:
            try:
                h, m, s = (int(x) for x in time.split(":"))
                total_time += 60 * 60 * h + 60 * m + s
            except ValueError:
                dq = True
                break
        if dq:
            print("{}: -".format(team.rjust(3, " ")))
            continue
        average_time = int(total_time / d + 0.5)
        print("{}: {}:{:02d} min/km".format(team.rjust(3, " "), average_time // 60, average_time % 60))


main()
