while True:
    scores = [int(x) for x in input().split()]
    if scores == [0] * 6:
        break
    scores.sort()
    print(str(sum(scores[1:5]) / 4.0).rstrip('0').rstrip('.'))
