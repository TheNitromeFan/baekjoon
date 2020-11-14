import sys


def main():
    for line in sys.stdin.readlines():
        dance = line.rstrip().split()
        errors = {1: [], 2: False, 3: False, 4: False, 5: False}
        for i, move in enumerate(dance):
            if move == "dip" and not ((i + 1 < len(dance) and dance[i + 1] == "twirl")
                                      or (i - 1 >= 0 and dance[i - 1] == "jiggle")
                                      or (i - 2 >= 0 and dance[i - 2] == "jiggle")):
                errors[1].append(i)
        if len(dance) < 3 or dance[-3:] != ["clap", "stomp", "clap"]:
            errors[2] = True
        if "twirl" in dance and "hop" not in dance:
            errors[3] = True
        if dance[0] == "jiggle":
            errors[4] = True
        if "dip" not in dance:
            errors[5] = True
        forms = [x for x in errors if errors[x]]
        if forms:
            if len(forms) > 1:
                print("form errors {} and {}:".format(", ".join(str(x) for x in forms[:-1]), forms[-1]), end=" ")
            else:
                print("form error {}:".format(str(forms[0])), end=" ")
            for i, _ in enumerate(dance):
                if i in errors[1]:
                    dance[i] = dance[i].upper()
            print(" ".join(dance))
        else:
            print("form ok: {}".format(" ".join(dance)))


main()
