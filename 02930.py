import sys


r = int(sys.stdin.readline())
sven = sys.stdin.readline().rstrip()
n = int(sys.stdin.readline())
friends = []
for _ in range(n):
    friends.append(sys.stdin.readline().rstrip())
points, max_points = 0, 0
for i in range(r):
    win, tie, lose = 0, 0, 0
    for j in range(n):
        if sven[i] == friends[j][i]:
            tie += 1
        elif (sven[i], friends[j][i]) in [('S', 'P'), ('P', 'R'), ('R', 'S')]:
            win += 1
        else:
            lose += 1
    points += 2 * win + tie
    max_points += max(2 * win + tie, 2 * tie + lose, 2 * lose + win)
print(points)
print(max_points)
