import sys
import math


def main():
    p, v = (int(x) for x in sys.stdin.readline().split())
    parties = []
    valid_votes = 0
    assigned_seats = {}
    independent = 253
    for i in range(p):
        entries = sys.stdin.readline().split()
        name, regional, votes = entries[0], int(entries[1]), int(entries[2])
        parties.append((i, name, regional, votes))
        valid_votes += votes
        assigned_seats[name] = regional
        independent -= regional
    seated_parties = []
    valid_seated_votes = 0
    for party in parties:
        regional, votes = party[2], party[3]
        if 100 * votes >= 3 * valid_votes or regional >= 5:
            seated_parties.append(party)
            valid_seated_votes += votes
        else:
            independent += regional
    seated_parties1 = []
    si_sum = 0
    for party in seated_parties:
        regional, votes = party[2], party[3]
        pi = votes / valid_seated_votes
        calc = ((300 - independent) * pi - regional) / 2
        if calc < 1:
            si = 0
        else:
            si = round(calc + 0.0000005)
        seated_parties1.append((*party, pi, si))
        si_sum += si
    if si_sum == 30:
        for party in seated_parties1:
            name, si = party[1], party[5]
            assigned_seats[name] += si
    elif si_sum < 30:
        linked = 30
        list1 = []
        for party in seated_parties1:
            i, name, pi, si = party[0], party[1], party[4], party[5]
            calc = si + (30 - si_sum) * pi
            int_s = int(calc)
            frac_s = calc - int_s
            assigned_seats[name] += int_s
            linked -= int_s
            list1.append((frac_s, i, name))
        list1.sort(key=lambda x: (-x[0], x[1]))
        for i in range(linked):
            name = list1[i][2]
            assigned_seats[name] += 1
    else:
        linked = 30
        list2 = []
        for party in seated_parties1:
            i, name, si = party[0], party[1], party[5]
            calc = 30 * si / si_sum
            int_s = int(calc)
            frac_s = calc - int_s
            assigned_seats[name] += int_s
            linked -= int_s
            list2.append((frac_s, i, name))
        list2.sort(key=lambda x: (-x[0], x[1]))
        for i in range(linked):
            name = list2[i][2]
            assigned_seats[name] += 1
    parallel = 17
    list3 = []
    for party in seated_parties1:
        i, name, pi = party[0], party[1], party[4]
        calc = 17 * pi
        int_t = int(calc)
        frac_t = calc - int_t
        assigned_seats[name] += int_t
        parallel -= int_t
        list3.append((frac_t, i, name))
    list3.sort(key=lambda x: (-x[0], x[1]))
    for i in range(parallel):
        name = list3[i][2]
        assigned_seats[name] += 1
    for name, votes in sorted(assigned_seats.items(), key=lambda x: (-x[1], x[0])):
        print(name, votes)


main()
