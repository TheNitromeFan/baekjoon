import sys


def main():
    rps = {
        "cs": {"Kamen": 0, "Nuzky": 1, "Papir": 2},
        "en": {"Rock": 0, "Scissors": 1, "Paper": 2},
        "fr": {"Pierre": 0, "Ciseaux": 1, "Feuille": 2},
        "de": {"Stein": 0, "Schere": 1, "Papier": 2},
        "hu": {"Ko": 0, "Koe": 0, "Ollo": 1, "Olloo": 1, "Papir": 2},
        "it": {"Sasso": 0, "Roccia": 0, "Forbice": 1, "Carta": 2, "Rete": 2},
        "jp": {"Guu": 0, "Choki": 1, "Paa": 2},
        "pl": {"Kamien": 0, "Nozyce": 1, "Papier": 2},
        "es": {"Piedra": 0, "Tijera": 1, "Papel": 2}
    }
    game = 0
    while True:
        language1, player1 = sys.stdin.readline().rstrip().split()
        language2, player2 = sys.stdin.readline().rstrip().split()
        score1, score2 = 0, 0
        game += 1
        while True:
            line = sys.stdin.readline().rstrip()
            if len(line) == 1:
                print(f"Game #{game}:")
                if score1 == 1:
                    print(f"{player1}: 1 point")
                else:
                    print(f"{player1}: {score1} points")
                if score2 == 1:
                    print(f"{player2}: 1 point")
                else:
                    print(f"{player2}: {score2} points")
                if score1 > score2:
                    print(f"WINNER: {player1}\n")
                elif score1 < score2:
                    print(f"WINNER: {player2}\n")
                else:
                    print("TIED GAME\n")
                if line == ".":
                    return
                break
            hand1, hand2 = line.split()
            move1, move2 = rps[language1][hand1], rps[language2][hand2]
            if (move1 - move2) % 3 == 2:
                score1 += 1
            elif (move1 - move2) % 3 == 1:
                score2 += 1


main()
