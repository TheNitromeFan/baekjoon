from sys import stdin
from collections import deque


def calc_score(cows, ew_fence, ns_fence):
    cnts = [0, 0, 0, 0]
    for cow in cows:
        i = (0 if cow[1] < ew_fence else 2) + (0 if cow[0] < ns_fence else 1)
        cnts[i] += 1
    return max(cnts)


def solve2(cows):
    xs, ys = zip(*cows)
    xs = sorted(x-1 for x in set(xs))
    ix = len(xs)//2

    ys = sorted(y-1 for y in set(ys))
    iy = len(ys)//2

    # print("Initial score = {} at ix,iy = ({},{})".format(calc_score(xs[ix],ys[iy]), ix, iy))

    seen = {(ix, iy)}

    queue = deque([(ix, iy)])

    best_score, best_ix, best_iy = calc_score(cows, xs[ix], ys[iy]), ix, iy

    while queue:
        ix, iy = queue.pop()
        # print("checking near: ix,iy = ({}, {})".format(ix, iy))

        for dx, dy in ((-1, 1), (0, 1), (1, 1),
                      (-1, 0),         (1, 0),
                      (-1, -1), (0, -1), (1, -1)):

            nx, ny = ix + dx, iy + dy

            if (nx, ny) in seen:
                # print("\t({},{}) - seen".format(nx, ny))
                continue

            seen.add((nx, ny))
            score = calc_score(cows, xs[nx], ys[ny])

            if score < best_score:
                best_score, best_ix, best_iy = score, nx, ny
                # print("\t({},{}) - new best score = {}".format(best_ix, best_iy, best_score))
                queue.clear()

            if score == best_score:
                queue.append((nx, ny))
                # print("\t({},{}) = enqueue".format(nx, ny))

    # print("\n best score = {} at ix,iy = ({},{}) = grid coords ({},{})".format(
    #        best_score, best_ix, best_iy, xs[best_ix], ys[best_iy]))

    return best_score, (xs[best_ix], ys[best_iy])


def main():
    n = int(stdin.readline())
    cows = []
    for _ in range(n):
        x, y = (int(x) for x in stdin.readline().split())
        cows.append((x, y))
    print(solve2(cows)[0])


main()
