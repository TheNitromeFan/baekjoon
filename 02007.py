import sys
import random


scanf = sys.stdin.readline
printf = sys.stdout.write


def simulate(sums, n, pos):
    if (sums[0] + sums[1] + sums[pos]) % 2 != 0:
        return False
    ans = []
    used = [False for _ in range(n * (n - 1) // 2)]
    unordered_map = {}
    for i in range(n * (n - 1) // 2):
        if sums[i] not in unordered_map:
            unordered_map[sums[i]] = []
        unordered_map[sums[i]].append(i)
    used[unordered_map[sums[0]][-1]] = True
    unordered_map[sums[0]].pop()
    used[unordered_map[sums[1]][-1]] = True
    unordered_map[sums[1]].pop()
    used[unordered_map[sums[pos]][-1]] = True
    unordered_map[sums[pos]].pop()
    ans.append((sums[0] + sums[1] - sums[pos]) // 2)
    ans.append((sums[0] + sums[pos] - sums[1]) // 2)
    ans.append((sums[1] + sums[pos] - sums[0]) // 2)
    idx = 0
    for j in range(3, n):
        while used[idx]:
            idx += 1
        ans.append(sums[idx] - ans[0])
        used[idx] = True
        for i in range(1, j):
            if ans[i] + ans[j] not in unordered_map or not unordered_map[ans[i] + ans[j]]:
                return False
            used[unordered_map[ans[i] + ans[j]][-1]] = True
            unordered_map[ans[i] + ans[j]].pop()
    if len(ans) != n:
        return False
    ans.sort()
    if ans[0] < -10 ** 8 or ans[-1] > 10 ** 8:
        return False
    new_sums = []
    for i in range(n):
        for j in range(i):
            new_sums.append(ans[i] + ans[j])
    if sorted(new_sums) != sums:
        return False
    return ans


def main():
    n = int(scanf())
    sums = sorted(int(x) for x in scanf().split())
    if n == 2:
        if sums[0] >= 0:
            printf(f"0 {sums[0]}")
        else:
            printf(f"{sums[0]} 0")
        return
    for pos in range(2, n * (n - 1) // 2):
        ans = simulate(sums, n, pos)
        if ans:
            printf(" ".join(str(x) for x in ans))
            return
    printf("Impossible")


main()
