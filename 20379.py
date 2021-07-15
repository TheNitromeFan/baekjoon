import sys


def main():
    adult_male = 1703
    adult_female = 3714
    newborn_male = 2058 * 2 // 3
    newborn_female = 1920 * 2 // 3
    fawn_male = 2058 - newborn_male
    fawn_female = 1920 - newborn_female
    n = int(sys.stdin.readline())
    sys.stdout.write("         HERD     ADULT     ADULT     MALE     FEMALE     MALE     FEMALE \n")
    sys.stdout.write("YEAR     SIZE     MALES    FEMALES    FAWNS     FAWNS    NEWBORN   NEWBORN\n")
    sys.stdout.write("----   -------   -------   -------   -------   -------   -------   -------\n")
    for year in range(1994, 1994 + n):
        sys.stdout.write("{0:4d}{1:10d}{2:10d}{3:10d}{4:10d}{5:10d}{6:10d}{7:10d}\n".format(
            year,
            adult_male + adult_female + fawn_male + fawn_female + newborn_male + newborn_female,
            adult_male,
            adult_female,
            fawn_male + newborn_male,
            fawn_female + newborn_female,
            newborn_male,
            newborn_female
        ))
        tmp = adult_female
        adult_male = (15 * adult_male + 60 * fawn_male + 50) // 100
        adult_female = (90 * adult_female + 60 * fawn_female + 50) // 100
        fawn_male = (55 * newborn_male + 50) // 100
        fawn_female = (55 * newborn_female + 50) // 100
        newborn_male = (52 * 150 * tmp + 5000) // 10000
        newborn_female = (48 * 150 * tmp + 5000) // 10000


main()
