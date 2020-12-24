import sys


def score(throw):
    if throw == "B":
        return 50
    elif throw == "OB":
        return 25
    elif throw == "M":
        return 0
    points = int(throw[1:])
    if throw[0] == "D":
        points *= 2
    elif throw[0] == "T":
        points *= 3
    return points


def simulate(game, num):
    score1, score2 = 301, 301
    sys.stdout.write("Game {}\n".format(num))
    sys.stdout.write("{}{}\n".format(str(score1).rjust(5), str(score2).rjust(5)))
    started1, started2 = False, False
    idx, n = 0, len(game)
    winner = 0
    player = 1
    turns = 0
    previous1, previous2 = score1, score2
    while idx < n:
        throw = game[idx]
        if player == 1:
            if not started1 and throw[0] in "BD":
                started1 = True
            if started1:
                score1 -= score(throw)
            if score1 == 0 and throw[0] in "DB":
                winner = 1
                break
            elif score1 < 2:
                score1 = previous1
                player = 2
                turns = 0
                idx += 1
                continue
            turns += 1
            if turns == 3:
                player = 2
                turns = 0
        else:
            if not started2 and throw[0] in "BD":
                started2 = True
            if started2:
                score2 -= score(throw)
            if score2 == 0 and throw[0] in "DB":
                winner = 2
                break
            elif score2 < 2:
                score2 = previous2
                player = 1
                turns = 0
                sys.stdout.write("{}{}\n".format(str(score1).rjust(5), str(score2).rjust(5)))
                previous1, previous2 = score1, score2
                idx += 1
                continue
            turns += 1
            if turns == 3:
                player = 1
                turns = 0
        if player == 1 and turns == 0:
            sys.stdout.write("{}{}\n".format(str(score1).rjust(5), str(score2).rjust(5)))
            previous1, previous2 = score1, score2
        idx += 1
    if not winner and score1 < score2:
        winner = 1
    elif not winner:
        winner = 2
    if winner == 1:
        sys.stdout.write(" Wins{}\n\n".format(str(previous2).rjust(5)))
    else:
        sys.stdout.write("{} Wins\n\n".format(str(previous1).rjust(5)))


def main():
    big_text = ""
    for line in sys.stdin.readlines():
        big_text += line.rstrip()
    throws = big_text.split(",")
    cnt = 0
    while True:
        idx = throws.index("#")
        if idx == 0:
            break
        cnt += 1
        game = throws[:idx]
        throws = throws[idx + 1:]
        simulate(game, cnt)


main()
