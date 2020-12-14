import sys


def main():
    n = int(sys.stdin.readline())
    runners1 = []
    for _ in range(n):
        name, first, other = sys.stdin.readline().rstrip().split()
        runners1.append((name, float(first), float(other)))
    runners2 = runners1[::]
    runners1.sort(key=lambda x: (x[2], x[1]))
    runners2.sort(key=lambda x: (x[1], x[2]))
    team = [runner[0] for runner in runners1[:3]]
    idx = 0
    time = sum(runner[2] for runner in runners1[:3])
    while runners2[idx][0] in team:
        idx += 1
    team = [runners2[idx][0]] + team
    time += runners2[idx][1]
    for i in range(3):
        alternative_team = [runner[0] for runner in runners1[:4]]
        new_time = sum(runner[2] for runner in runners1[:4])
        alternative_team.pop(i)
        new_time -= runners1[i][2]
        idx = 0
        while runners2[idx][0] in alternative_team:
            idx += 1
        alternative_team = [runners2[idx][0]] + alternative_team
        new_time += runners2[idx][1]
        if new_time < time:
            time = new_time
            team = alternative_team[::]
    sys.stdout.write("{}\n{}".format(time, "\n".join(team)))


main()
