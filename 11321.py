import sys


def indices(numbers):
    for i in range(len(numbers)):
        for j in range(i):
            if (numbers[j] + numbers[i]) % 10 == 0:
                return j, i
    return -1, -1


def main():
    while True:
        line = sys.stdin.readline().rstrip()
        numbers = [int(x) for x in line.split("+")]
        if numbers == [0]:
            break
        reordered = []
        while True:
            j, i = indices(numbers)
            if j == i == -1:
                break
            reordered.append(numbers.pop(i))
            reordered.append(numbers.pop(j))
        reordered += numbers
        print("+".join(str(x) for x in reordered))


main()
