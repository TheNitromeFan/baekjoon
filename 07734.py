import itertools


def main():
    points = [(200931, 852577), (16620, 835131), (238356, 716457), (283813, 693727), (396833, 884789),
              (236124, 312729), (433443, 902896), (634891, 927579), (987398, 529528), (74553, 65407)]
    min_sum = 10 ** 100
    permutation = points[::]
    j = 0
    for p in itertools.permutations(points):
        j += 1
        current_sum = 0
        for i in range(10):
            current_sum += ((p[i][0] - p[i - 1][0]) ** 2 + (p[i][1] - p[i - 1][1]) ** 2) ** 0.5
        if current_sum < min_sum:
            min_sum = current_sum
            permutation = p
        print(j)
    print(permutation)


main()
