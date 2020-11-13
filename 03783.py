def main():
    for _ in range(int(input())):
        n = int(input())
        n *= 10 ** 30
        answer = 0
        for power in range(60, -1, -1):
            for digit in range(10):
                if (answer + digit * 10 ** power) ** 3 <= n < (answer + (digit + 1) * 10 ** power) ** 3:
                    answer += digit * 10 ** power
                    continue
        to_string = str(answer)
        print(to_string[:-10] + "." + to_string[-10:])


main()
