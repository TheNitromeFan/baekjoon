import math


def multi_combination(list1):
    n = sum(list1)
    ret = math.factorial(n)
    for k in list1:
        ret //= math.factorial(k)
    return ret


def pad_spaces(string, length, left):
    if left:
        return " " * (length - len(string)) + string
    else:
        return string + " " * (length - len(string))


def main():
    with open("06358.txt", "w") as f:
        f.write("Round   A wins    B wins    Tie\n")
        scores = {3: 1, 2: 2, 1: 4, 0: 6, -1: 2, -3: 1}
        results = [{0: 1}]
        for round in range(1, 21):
            results.append({})
            for x in results[round - 1]:
                for score in scores:
                    if x + score in results[round]:
                        results[round][x + score] += results[round - 1][x] * scores[score]
                    else:
                        results[round][x + score] = results[round - 1][x] * scores[score]
            print(results[round])
            a_wins, b_wins, ties = 0, 0, 0
            for result in results[round]:
                if result > 0:
                    a_wins += results[round][result]
                elif result < 0:
                    b_wins += results[round][result]
                else:
                    ties += results[round][result]
            total = 16 ** round
            print(a_wins, b_wins, ties)
            f.write("{}   {}{}{}\n".format(
                pad_spaces(str(round), 5, True),
                pad_spaces("{:.4f}".format(a_wins * 100 / total) + "%", 10, False),
                pad_spaces("{:.4f}".format(b_wins * 100 / total) + "%", 10, False),
                "{:.4f}".format(ties * 100 / total) + "%"
            ))


main()
