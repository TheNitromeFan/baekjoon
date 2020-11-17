import sys


def main():
    n = int(sys.stdin.readline())
    commands = ["ADDC", "SUBC", "MOVC", "ANDC", "ORC", "NOT", "MULTC", "LSFTLC", "LSFTRC", "ASFTRC", "RLC", "RRC"]
    for _ in range(n):
        entries = sys.stdin.readline().split()
        command, rd, ra, rb = entries[0], int(entries[1]), int(entries[2]), int(entries[3])
        binary = ""
        for ind, com in enumerate(commands):
            if command in com:
                binary += bin(ind)[2:].zfill(4)
        if command[-1] == "C":
            binary += "1"
        else:
            binary += "0"
        binary += bin(rd)[2:].zfill(4)
        if command in ["MOV", "MOVC", "NOT"]:
            binary += "000"
        else:
            binary += bin(ra)[2:].zfill(3)
        if command[-1] == "C":
            binary += bin(rb)[2:].zfill(4)
        else:
            binary += bin(rb)[2:].zfill(3) + "0"
        print(binary)


main()
