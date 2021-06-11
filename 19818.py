import sys


references = []
while True:
    line = sys.stdin.readline()[:-1]
    if line == "\\begin{thebibliography}{99}":
        break
    for idx in range(len(line) - 4):
        if line[idx:idx + 5] == "\cite":
            reference = ""
            i = idx + 6
            while line[i] != "}":
                reference += line[i]
                i += 1
            references.append(reference)
references1 = []
bibliography = {}
while True:
    line = sys.stdin.readline()[:-1]
    if line == "\end{thebibliography}":
        break
    reference = ""
    i = 9
    while line[i] != "}":
        reference += line[i]
        i += 1
    references1.append(reference)
    bibliography[reference] = line[i + 1:]
if references != references1:
    print("Incorrect")
    print("\\begin{thebibliography}{99}")
    for reference in references:
        print(f"\\bibitem{{{reference}}}{bibliography[reference]}")
    print("\end{thebibliography}")
else:
    print("Correct")
