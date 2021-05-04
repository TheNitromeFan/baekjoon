import sys


def main():
    lead, follow, songs = (int(x) for x in sys.stdin.readline().split())
    leaders, followers = [0] * 8, [0] * 8
    for _ in lead:
        dances = sys.stdin.readline().rstrip().split()[1:]
        number = 0
        if "swing" in dances:
            number += 4
        if "country" in dances:
            number += 2
        if "bachata" in dances:
            number += 1
        leaders[number] += 1
    for _ in follow:
        dances = sys.stdin.readline().rstrip().split()[1:]
        number = 0
        if "swing" in dances:
            number += 4
        if "country" in dances:
            number += 2
        if "bachata" in dances:
            number += 1
        followers[number] += 1
    three_dances = min(leaders[7], followers[7])
    leaders[7] -= three_dances
    followers[7] -= three_dances
    two_dances1, two_dances2, two_dances3 \
        = min(leaders[3], followers[3]), min(leaders[5], followers[5]), min(leaders[6], followers[6])
    leaders[3] -= two_dances1
    followers[3] -= two_dances1
    leaders[5] -= two_dances2
    followers[5] -= two_dances2
    leaders[6] -= two_dances3
    followers[6] -= two_dances3
    one_dance1, one_dance2, one_dance3 \
        = min(leaders[1], followers[1]), min(leaders[2], followers[2]), min(leaders[4], followers[4])
    leaders[1] -= one_dance1
    followers[1] -= one_dance1
    leaders[2] -= one_dance2
    followers[2] -= one_dance2
    leaders[4] -= one_dance3
    followers[4] -= one_dance3




main()
