import sys

CODONS = {
    "UUU": "Phe", "UCU": "Ser", "UAU": "Tyr", "UGU": "Cys",
    "UUC": "Phe", "UCC": "Ser", "UAC": "Tyr", "UGC": "Cys",
    "UUA": "Leu", "UCA": "Ser",
    "UUG": "Leu", "UCG": "Ser",               "UGG": "Trp",
    "CUU": "Leu", "CCU": "Pro", "CAU": "His", "CGU": "Arg",
    "CUC": "Leu", "CCC": "Pro", "CAC": "His", "CGC": "Arg",
    "CUA": "Leu", "CCA": "Pro", "CAA": "Gln", "CGA": "Arg",
    "CUG": "Leu", "CCG": "Pro", "CAG": "Gln", "CGG": "Arg",
    "AUU": "Ile", "ACU": "Thr", "AAU": "Asn", "AGU": "Ser",
    "AUC": "Ile", "ACC": "Thr", "AAC": "Asn", "AGC": "Ser",
    "AUA": "Ile", "ACA": "Thr", "AAA": "Lys", "AGA": "Arg",
    "AUG": "Met", "ACG": "Thr", "AAG": "Lys", "AGG": "Arg",
    "GUU": "Val", "GCU": "Ala", "GAU": "Asp", "GGU": "Gly",
    "GUC": "Val", "GCC": "Ala", "GAC": "Asp", "GGC": "Gly",
    "GUA": "Val", "GCA": "Ala", "GAA": "Glu", "GGA": "Gly",
    "GUG": "Val", "GCG": "Ala", "GAG": "Glu", "GGG": "Gly"
}
COMP = {"A": "U", "U": "A", "C": "G", "G": "C"}


def complement(strand):
    return "".join(COMP[c] for c in strand)


def get_proteins(strand, i, j):
    ret = []
    for k in range(i, j, 3):
        try:
            ret.append(CODONS[strand[k:k + 3]])
        except ValueError:
            return []
    return ret


def proteins(strand):
    n = len(strand)
    start = [x for x in range(n) if strand[x:x + 3] == "AUG"]
    end = [x for x in range(n) if strand[x:x + 3] in ["UAA", "UAG", "UGA"]]
    for i in start:
        for j in end:
            if i <= j and i % 3 == j % 3:
                ret = get_proteins(strand, i + 3, j)
                if ret:
                    return ret
    return []


def main():
    while True:
        strand = sys.stdin.readline().rstrip().replace("T", "U")
        if strand[0] == "*":
            break
        strand1 = complement(strand)
        # print(strand, strand1)
        ans = [proteins(x) for x in [strand, strand[::-1], strand1[::-1], strand1]]
        if any(ans):
            for x in ans:
                if x:
                    print("-".join(x))
                    break
        else:
            print("*** No translatable DNA found ***")


main()
