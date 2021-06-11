import sys


def good_marks(a, m, start, end):
    for i in range(start, m, end - start):
        if i not in a:
            return False
    return True


def main():
    try:
        while True:
            line = sys.stdin.readline()
            entries = [int(x) for x in line.split()]
            m, n, a = entries[0], entries[1], entries[2:]
            cnt = 0
            a_used = {x: False for x in a}
            while not all(a_used.values()):
                cnt += 1
                start = min(x for x in a_used if not a_used[x])
                if start == max(a):
                    break
                for end in range(start + 1, m):
                    if end in a and not a_used[end] and good_marks(a_used, m, start, end):
                        break
                for i in range(start, m, end - start):
                    a_used[i] = True
            print(cnt)
    except (EOFError, ValueError, IndexError):
        return


main()
