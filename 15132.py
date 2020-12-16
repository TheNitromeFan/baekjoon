import string


dnf = input()
clauses = set(dnf.split("|"))
count = 0
tautology = False
for variable in string.ascii_letters:
    if variable in clauses or "~" + variable in clauses:
        count += 1
        if variable in clauses and "~" + variable in clauses:
            tautology = True
if tautology:
    print(2 ** count)
else:
    print(2 ** count - 1)
