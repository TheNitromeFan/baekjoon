import sys
import datetime


def main():
    n = int(sys.stdin.readline())
    entries = sys.stdin.readline().split()
    my_time = datetime.datetime.strptime(entries[0], "%H:%M")
    my_time += datetime.timedelta(days=1)
    my_time_zone = float(entries[1][3:])
    for _ in range(n):
        new_time_zone = float(sys.stdin.readline()[3:])
        new_time = my_time - datetime.timedelta(
            minutes=int(my_time_zone * 60)) + datetime.timedelta(minutes=int(new_time_zone * 60))
        sys.stdout.write(new_time.strftime("%H:%M\n"))


main()
