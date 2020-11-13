def main():
    n = int(input())
    solved = set()
    wrong = {}
    for _ in range(n):
        info = input().split()
        username, result = info[1], info[2]
        if username == "megalusion" or username in solved:
            continue
        if result == "4":
            solved.add(username)
            if username not in wrong:
                wrong[username] = 0
        else:
            if username in wrong:
                wrong[username] += 1
            else:
                wrong[username] = 1
    numerator = len(solved)
    denominator = len(solved) + sum(wrong[username] for username in solved)
    if denominator == 0:
        print(0)
    else:
        print(numerator * 100 / denominator)


main()
