import sys


def main():
    problems = {"L": 120, "S": 150, "B": 150, "N": 40, "C": 160, "D": 100, "R": 100, "O": 100}
    while True:
        flight_number = sys.stdin.readline().rstrip()
        if flight_number == "#":
            break
        points = {}
        while True:
            line = sys.stdin.readline().rstrip()
            if line == "00A":
                break
            seat, code = line.split()
            if code not in problems:
                continue
            if seat in points:
                points[seat] += problems[code]
            else:
                points[seat] = problems[code]
        sys.stdout.write(f"{flight_number} {len([seat for seat in points if points[seat] >= 200])}\n")


main()
