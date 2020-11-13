n = int(input())
for i in range(1, n + 1):
    a, b = (int(x) for x in input().split())
    print("Scenario #{}:\n{}\n".format(i, (a + b) * (b - a + 1) // 2))
