import sys


dist = {"HP": 103, "HS": 329, "HK": 466, "HT": 148, "PS": 408, "PK": 577, "PT": 260, "SK": 287, "ST": 226, "KT": 312}
n = int(sys.stdin.readline())
for i in range(1, n + 1):
    campuses = sys.stdin.readline().rstrip() + "H"
    previous = "H"
    ans = 0
    for campus in campuses:
        if previous + campus in dist:
            ans += dist[previous + campus]
        elif campus + previous in dist:
            ans += dist[campus + previous]
        previous = campus
    sys.stdout.write("Case {}: {}\n".format(i, ans))
