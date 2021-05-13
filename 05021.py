import sys


def main():
    n, m = (int(x) for x in sys.stdin.readline().split())
    founder = sys.stdin.readline().rstrip()
    adj, degree = {}, {}
    for _ in range(n):
        child, parent1, parent2 = sys.stdin.readline().rstrip().split()
        if parent1 not in adj:
            adj[parent1] = []
            degree[parent1] = 0
        if parent2 not in adj:
            adj[parent2] = []
            degree[parent2] = 0
        if child not in adj:
            adj[child] = []
            degree[child] = 0
        adj[parent1].append(child)
        adj[parent2].append(child)
        degree[child] += 2
    claimants = []
    for _ in range(m):
        claimant = sys.stdin.readline().rstrip()
        if claimant not in adj:
            adj[claimant] = []
            degree[claimant] = 0
        claimants.append(claimant)
    blood = {x: 0 for x in adj}
    blood[founder] = 2 ** 60
    people = [x for x in adj]
    people.sort(key=lambda x: degree[x], reverse=True)
    while people:
        person = people.pop()
        # print(person, degree[person])
        for child in adj[person]:
            blood[child] += blood[person] // 2
            degree[child] -= 1
        people.sort(key=lambda x: degree[x], reverse=True)
    # print(blood)
    print(max(claimants, key=lambda x: blood[x]))


main()
