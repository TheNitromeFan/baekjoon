import sys
import string


def interp(mol):
    # print(mol)
    atom_counts = {}
    idx = 0
    m = len(mol)
    count = 0
    while idx < m and mol[idx] in string.digits:
        count = count * 10 + int(mol[idx])
        idx += 1
    cur = ""
    while idx < m:
        if mol[idx] == "(":
            left_paren = 1
            if cur:
                if cur in atom_counts:
                    atom_counts[cur] += 1
                else:
                    atom_counts[cur] = 1
            cur = mol[idx]
            idx += 1
            while idx < m:
                cur += mol[idx]
                if mol[idx] == ")":
                    left_paren -= 1
                elif mol[idx] == "(":
                    left_paren += 1
                if left_paren == 0:
                    break
                idx += 1
            sub_atom_counts = interp(cur[1:-1])
            idx += 1
            sub_count = 0
            while idx < m and mol[idx] in string.digits:
                sub_count = sub_count * 10 + int(mol[idx])
                idx += 1
            if sub_count == 0:
                sub_count = 1
            for atom, val in sub_atom_counts.items():
                if atom in atom_counts:
                    atom_counts[atom] += val * sub_count
                else:
                    atom_counts[atom] = val * sub_count
            cur = ""
        elif mol[idx] in string.digits:
            atom_count = 0
            while idx < m and mol[idx] in string.digits:
                atom_count = atom_count * 10 + int(mol[idx])
                idx += 1
            if cur in atom_counts:
                atom_counts[cur] += atom_count
            else:
                atom_counts[cur] = atom_count
            cur = ""
        elif mol[idx] in string.ascii_uppercase:
            if cur:
                if cur in atom_counts:
                    atom_counts[cur] += 1
                else:
                    atom_counts[cur] = 1
            cur = mol[idx]
            idx += 1
        else:
            cur += mol[idx]
            idx += 1
        # print(idx)
    if cur:
        if cur in atom_counts:
            atom_counts[cur] += 1
        else:
            atom_counts[cur] = 1
    if count == 0:
        count = 1
    for atom, val in atom_counts.items():
        atom_counts[atom] = val * count
    return atom_counts


def evaluate(expr):
    molecules = expr.split("+")
    atom_counts = {}
    for molecule in molecules:
        counts = interp(molecule)
        for atom, val in counts.items():
            if atom in atom_counts:
                atom_counts[atom] += val
            else:
                atom_counts[atom] = val
    return atom_counts


def main():
    lhs = sys.stdin.readline().rstrip()
    cmp = evaluate(lhs)
    n = int(sys.stdin.readline())
    for _ in range(n):
        rhs = sys.stdin.readline().rstrip()
        # print(cmp, evaluate(rhs))
        if evaluate(rhs) == cmp:
            sys.stdout.write("{}=={}\n".format(lhs, rhs))
        else:
            sys.stdout.write("{}!={}\n".format(lhs, rhs))


main()
