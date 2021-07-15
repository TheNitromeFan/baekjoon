import sys


def transfer(balls, vase):
    if balls > sum(vase):
        balls = sum(vase)
    ret = [0, 0, 0, 0, 0]
    if balls == 0:
        return ret
    remainders = []
    for i in range(5):
        q, r = divmod(balls * vase[i], sum(vase))
        ret[i] = q
        remainders.append((i, r))
    remainders.sort(key=lambda x: (-x[1], -x[0]))
    idx = 0
    while sum(ret) < balls:
        x = remainders[idx]
        ret[x[0]] += 1
        idx += 1
    return ret


def main():
    while True:
        trial = sys.stdin.readline().rstrip()
        if trial == "#":
            break
        vase = [[0, 0, 0, 0, 0]]
        entries = [int(x) for x in sys.stdin.readline().split()][:5]
        for i, entry in enumerate(entries):
            new_vase = [0, 0, 0, 0, 0]
            new_vase[i] = entry
            vase.append(new_vase)
        while True:
            balls, src, dest = (int(x) for x in sys.stdin.readline().split())
            if balls == src == dest == 0:
                break
            t = transfer(balls, vase[src])
            for i in range(5):
                vase[src][i] -= t[i]
                vase[dest][i] += t[i]
        sys.stdout.write(f"{trial}\n")
        sys.stdout.write("URN        R      O      Y      G      B\n")
        for i in range(1, 6):
            sys.stdout.write(f"{i}{vase[i][0]:11d}{vase[i][1]:7d}{vase[i][2]:7d}{vase[i][3]:7d}{vase[i][4]:7d}\n")
        sys.stdout.write("\n")


main()
