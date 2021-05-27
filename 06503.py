import sys


while True:
    m = int(sys.stdin.readline())
    if m == 0:
        break
    line = sys.stdin.readline().rstrip()
    start, end = 0, 0
    chars = {}
    ans = 0
    while end < len(line):
        if line[end] in chars:
            chars[line[end]] += 1
        else:
            chars[line[end]] = 1
        end += 1
        while len(chars) > m:
            chars[line[start]] -= 1
            if chars[line[start]] == 0:
                chars.pop(line[start])
            start += 1
        ans = max(ans, end - start)
    print(ans)
