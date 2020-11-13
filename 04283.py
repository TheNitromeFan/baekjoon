import math


def preprocess():
    for y in range(1960, 2161, 10):
        bits = 2 ** ((y - 1960) // 10 + 2)
        low, high = 1, 500000
        ans = low
        while low <= high:
            mid = (low + high) // 2
            if math.factorial(mid) <= 2 ** bits - 1:
                ans = mid
                low = mid + 1
            else:
                high = mid - 1
        print(ans)


def main():
    answers = [3, 5, 8, 12, 20, 34, 57, 98, 170, 300, 536, 966, 1754,
               3210, 5910, 10944, 20366, 38064, 71421, 134480, 254016]
    while True:
        y = int(input())
        if y == 0:
            break
        print(answers[(y - 1960) // 10])


main()
