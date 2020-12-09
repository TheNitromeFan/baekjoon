import sys


def match(dudu, station, pos):
    station_to_dudu, dudu_to_station = {}, {}
    for i, letter_station in enumerate(station):
        j = i + pos
        letter_dudu = dudu[j]
        if letter_station in station_to_dudu and station_to_dudu[letter_station] != letter_dudu:
            return False
        if letter_dudu in dudu_to_station and dudu_to_station[letter_dudu] != letter_station:
            return False
        station_to_dudu[letter_station] = letter_dudu
        dudu_to_station[letter_dudu] = letter_station
    return True


def can_appear(dudu, station):
    for i in range(len(dudu) - len(station) + 1):
        if match(dudu, station, i):
            return i
    return "-"


def main():
    n = int(sys.stdin.readline())
    dudu = sys.stdin.readline().rstrip()
    for _ in range(n):
        station = sys.stdin.readline().rstrip()
        sys.stdout.write("{}\n".format(can_appear(dudu, station)))


main()
