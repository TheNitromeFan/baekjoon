import sys


def find_len(n):
    if n <= 9:
        return n
    else:
        return 2 * (n - 9) + 9


def find_sequence(s, n, idx, permutation):
    if len(permutation) == n:
        return permutation
    if idx >= len(s) or s[idx] == "0":
        return []
    current_num = int(s[idx])
    while idx < len(s) and current_num <= n:
        if 1 <= current_num <= n and current_num not in permutation:
            cmp = find_sequence(s, n, idx + 1, permutation + [current_num])
            if cmp:
                return cmp
        idx += 1
        current_num = current_num * 10 + int(s[idx])
    return []


def main():
    s = sys.stdin.readline().rstrip()
    n = 0
    for i in range(1, 51):
        if find_len(i) == len(s):
            n = i
            break
    sys.stdout.write(" ".join(str(x) for x in find_sequence(s, n, 0, [])))


main()
