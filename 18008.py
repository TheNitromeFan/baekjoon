import sys
import string
import heapq


def generate_code_lengths():
    h = [1, 3]
    heapq.heapify(h)
    ret = []
    while len(ret) < 26:
        x = heapq.heappop(h)
        ret.append(x)
        heapq.heappush(h, x + 2)
        heapq.heappush(h, x + 4)
    return ret


s = sys.stdin.readline().rstrip().upper()
tally = {x: 0 for x in string.ascii_uppercase}
message = 0
for letter in s:
    if letter in string.ascii_uppercase:
        tally[letter] += 1
        message += 1
v = sorted(tally.values(), reverse=True)
codes = generate_code_lengths()
ans = 3 * (message - 1)
for i in range(26):
    ans += codes[i] * v[i]
print(ans)
