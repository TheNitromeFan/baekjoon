import sys


def main():
    n = int(sys.stdin.readline())
    attempts = {}
    for _ in range(n):
        entries = sys.stdin.readline().rstrip().split()
        time, team, problem, result = int(entries[0]), entries[1], entries[2], entries[3]
        if team not in attempts:
            attempts[team] = {}
        if problem in attempts[team]:
            if result == "A" and not attempts[team][problem][0]:
                attempts[team][problem][0] = True
                attempts[team][problem][1] += 1
                attempts[team][problem][2] = time
            elif not attempts[team][problem][0]:
                attempts[team][problem][1] += 1
        else:
            attempts[team][problem] = [False, 0, None]
            if result == "A":
                attempts[team][problem][0] = True
                attempts[team][problem][1] += 1
                attempts[team][problem][2] = time
            else:
                attempts[team][problem][1] += 1
    for problem in "ABCDEFGHI":
        solved, submissions, time = 0, 0, 0
        for team in attempts:
            if problem in attempts[team] and attempts[team][problem][0]:
                solved += 1
                submissions += attempts[team][problem][1]
                time += attempts[team][problem][2]
        if solved:
            print(f"{problem} {solved} {submissions / solved :.2f} {time / solved :.2f}")
        else:
            print(f"{problem} 0")


main()
