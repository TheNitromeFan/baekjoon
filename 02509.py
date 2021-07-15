import sys


def is_match(text, pattern, k):
    i = k
    j = 0
    current_sum = 0
    while j < len(pattern):
        if i == len(text):
            return -1
        current_sum += text[i]
        if current_sum > pattern[j]:
            return 0
        elif current_sum == pattern[j]:
            j += 1
            current_sum = 0
        i += 1
    return int(j == len(pattern))


def main():
    t = int(sys.stdin.readline())
    for _ in range(t):
        sys.stdin.readline()
        sys.stdin.readline()
        text = [int(x) for x in sys.stdin.readline().split()]
        sys.stdin.readline()
        pattern1 = [int(x) for x in sys.stdin.readline().split()]
        sys.stdin.readline()
        pattern2 = [int(x) for x in sys.stdin.readline().split()]
        cnt1, cnt2 = 0, 0
        for k, _ in enumerate(text):
            cmp = is_match(text, pattern1, k)
            if cmp == 1:
                cnt1 += 1
            elif cmp == -1:
                break
        for k, _ in enumerate(text):
            cmp = is_match(text, pattern2, k)
            if cmp == 1:
                cnt2 += 1
            elif cmp == -1:
                break
        ans, max_matches = -1, -1
        for n in range(1, 11001):
            pattern = pattern1 + [n] + pattern2
            cnt = 0
            for k, _ in enumerate(text):
                cmp = is_match(text, pattern, k)
                if cmp == 1:
                    cnt += 1
                elif cmp == -1:
                    break
            if max_matches < cnt:
                ans = n
                max_matches = cnt
        print(cnt1, cnt2, ans, max_matches)


main()
