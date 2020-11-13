import string


def simulate_match(players, turns):
    turn_scores = {x: 0 for x in players}
    game_scores = {x: 0 for x in players}
    set_scores = {x: 0 for x in players}
    for turn in turns:
        if turn_scores[turn] == 3 and all(turn_scores[x] < 2 for x in players if x != turn):
            game_scores[turn] += 1
            if game_scores[turn] >= 6 and all(game_scores[turn] - game_scores[x] >= 2 for x in players if x != turn):
                set_scores[turn] += 1
                if all(game_scores[x] == 0 for x in players if x != turn):
                    set_scores[turn] += 1
                if set_scores[turn] >= 3:
                    return turn
                game_scores = {x: 0 for x in players}
            turn_scores = {x: 0 for x in players}
            # print(turn_scores, game_scores, set_scores)
            continue
        elif turn_scores[turn] == 4:
            game_scores[turn] += 1
            if game_scores[turn] >= 6 and all(game_scores[turn] - game_scores[x] >= 2 for x in players if x != turn):
                set_scores[turn] += 1
                if all(game_scores[x] == 0 for x in players if x != turn):
                    set_scores[turn] += 1
                if set_scores[turn] >= 3:
                    return turn
                game_scores = {x: 0 for x in players}
            turn_scores = {x: 0 for x in players}
            # print(turn_scores, game_scores, set_scores)
            continue
        for x in players:
            if x != turn and turn_scores[x] == 4:
                turn_scores[x] -= 1
        turn_scores[turn] += 1
        # print(turn_scores, game_scores, set_scores)


def main():
    # entries = input().split()
    # n, s = int(entries[0]), entries[1]
    # players = string.ascii_uppercase[:n]
    # print(simulate_match(players, s))
    line = input()
    print(line[-1])


main()
