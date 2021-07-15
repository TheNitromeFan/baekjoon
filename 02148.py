import sys


def main():
    table = {}
    while True:
        team = sys.stdin.readline().rstrip()
        if team == "#":
            break
        table[team] = [0, 0, 0, 0, 0]
    n = len(table)
    match_count = 0
    round_count = 1
    while True:
        line = sys.stdin.readline().rstrip()
        if line == "#":
            break
        match_count += 1
        team1, team2, score1, score2, tries1, tries2 = line.split()
        score1, score2, tries1, tries2 = int(score1), int(score2), int(tries1), int(tries2)
        table[team1][1] += score1
        table[team1][2] += score2
        table[team1][3] += tries1
        table[team1][4] += tries2
        table[team2][1] += score2
        table[team2][2] += score1
        table[team2][3] += tries2
        table[team2][4] += tries1
        if score1 > score2:
            table[team1][0] += 4
            if score1 - score2 < 8:
                table[team2][0] += 1
        elif score1 < score2:
            table[team2][0] += 4
            if score2 - score1 < 8:
                table[team1][0] += 1
        else:
            table[team1][0] += 2
            table[team2][0] += 2
        if tries1 >= 4:
            table[team1][0] += 1
        if tries2 >= 4:
            table[team2][0] += 1
        if match_count == n // 2:
            standings = list(table.items())
            standings.sort(key=lambda x: (-x[1][0], -(x[1][1] - x[1][2]), -x[1][3], x[0]))
            sys.stdout.write(f"Round {round_count}\n")
            for team, data in standings:
                sys.stdout.write(f"{team.ljust(21, ' ')}{str(data[0]).rjust(2, ' ')}{str(data[1]).rjust(4, ' ')}{str(data[2]).rjust(4, ' ')}{str(data[3]).rjust(3, ' ')}{str(data[4]).rjust(3, ' ')}\n")
            sys.stdout.write("\n")
            round_count += 1
            match_count = 0


main()
