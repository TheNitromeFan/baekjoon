import sys


def main():
    n, k = (int(x) for x in sys.stdin.readline().split())
    a = [int(x) for x in sys.stdin.readline().split()]
    balls = {}
    for ai in a:
        if ai not in balls:
            balls[ai] = 0
        balls[ai] += 1
    gift = []
    for key in balls.keys():
        gift.append(key)
        balls[key] -= 1
        if len(gift) == k:
            break
    for key in balls.keys():
        while len(gift) < k and balls[key] > 0:
            gift.append(key)
            balls[key] -= 1
    print(" ".join(str(x) for x in gift))


main()
