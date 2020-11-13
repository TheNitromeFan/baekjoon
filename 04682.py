import sys


def main():
    for line in sys.stdin.readlines():
        c = [int(x) for x in line.rstrip().split()]
        summands = []
        if c == [0] * 9:
            print("0")
            continue
        first = True
        for i, ci in enumerate(c):
            if ci and first:
                if i < 7:
                    if ci == 1:
                        summands.append("x^{}".format(8 - i))
                    elif ci == -1:
                        summands.append("-x^{}".format(8 - i))
                    else:
                        summands.append(str(ci) + "x^{}".format(8 - i))
                elif i == 7:
                    if ci == 1:
                        summands.append("x")
                    elif ci == -1:
                        summands.append("-x")
                    else:
                        summands.append(str(ci) + "x")
                else:
                    summands.append(str(ci))
                first = False
            elif ci < 0:
                if i < 7:
                    if ci == -1:
                        summands.append("- x^{}".format(8 - i))
                    else:
                        summands.append("- " + str(-ci) + "x^{}".format(8 - i))
                elif i == 7:
                    if ci == -1:
                        summands.append("- x")
                    else:
                        summands.append("- " + str(-ci) + "x")
                else:
                    summands.append("- " + str(-ci))
            elif ci > 0:
                if i < 7:
                    if ci == 1:
                        summands.append("+ x^{}".format(8 - i))
                    else:
                        summands.append("+ " + str(ci) + "x^{}".format(8 - i))
                elif i == 7:
                    if ci == 1:
                        summands.append("+ x")
                    else:
                        summands.append("+ " + str(ci) + "x")
                else:
                    summands.append("+ " + str(ci))
        print(" ".join(summands))


main()
