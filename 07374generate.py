import sys


def simulate(k, m):
    circle = list(range(1, 2 * k + 1))
    index = 2 * k - 1
    while len(circle) > k:
        index = (index + m) % len(circle)
        if circle[index] <= k:
            return False
        circle.pop(index)
        index = (index + len(circle) - 1) % len(circle)
    return True


def main():
    ans = []
    for k in range(1, 14):
        for m in range(1, 100000000000):
            if simulate(k, m):
                ans.append(m)
                break
    print(ans)


main()
