k = int(input())
for i in range(1, k + 1):
    marks = sorted(int(x) for x in input().split()[1:])
    print("Class {}".format(i))
    max_gap = max(marks[j + 1] - marks[j] for j in range(0, len(marks) - 1))
    print("Max {}, Min {}, Largest gap {}".format(marks[-1], marks[0], max_gap))
