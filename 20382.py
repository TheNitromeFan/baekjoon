import datetime
import sys


def main():
    for line in sys.stdin.readlines():
        line = line.rstrip()
        if not line:
            break
        entries = line.split()
        channel, month, day, year, time, duration \
            = int(entries[1][:-1]), datetime.datetime.strptime(entries[2], "%B").month, int(entries[3]),\
            int(entries[4][:-1]), entries[5], entries[6]
        datetime1 = datetime.datetime.strptime(time.upper(), "%I:%M%p")
        start = datetime1.hour * 60 + datetime1.minute
        length = int(duration[:-3])
        print((year - 1994) * 2 ** 25 + channel * 2 ** 19 + month * 2 ** 15 + day * 2 ** 10 + start // 30 * 2 ** 4 + length // 30)


main()
