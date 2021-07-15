import sys
import collections


def main():
    n = int(sys.stdin.readline())
    relations = []
    for _ in range(n):
        name1, name2, relation = sys.stdin.readline().rstrip().split()
        relations.append((name1, name2, relation))
    adj = {}
    gender = {}
    marriage = {}
    for name1, name2, relation in relations:
        if relation not in ["husband", "wife"]:
            continue
        if name1 not in adj:
            adj[name1] = []
            gender[name1] = None
            marriage[name1] = None
        if name2 not in adj:
            adj[name2] = []
            gender[name2] = None
            marriage[name2] = None
        if relation == "husband":
            couple = (name1, name2)
            gender[name1] = "male"
            gender[name2] = "female"
        else:
            couple = (name2, name1)
            gender[name1] = "female"
            gender[name2] = "male"
        adj[name1].append((couple, "spouse"))
        adj[name2].append((couple, "spouse"))
        if couple not in adj:
            adj[couple] = []
        adj[couple].append((name1, "spouse"))
        adj[couple].append((name2, "spouse"))
        marriage[name1] = couple
        marriage[name2] = couple
    parent_list = {}
    for name1, name2, relation in relations:
        if relation not in ["son", "daughter"]:
            continue
        if name1 not in adj:
            adj[name1] = []
            gender[name1] = None
        if name2 in marriage:
            parents = marriage[name2]
            adj[name1].append((parents, "parent"))
            adj[parents].append((name1, "child"))
        else:
            adj[name2] = []
            if name1 not in parent_list:
                parent_list[name1] = []
            parent_list[name1].append(name2)
        if relation == "son":
            gender[name1] = "male"
        else:
            gender[name1] = "female"
    for child in parent_list:
        parent1, parent2 = parent_list[child]
        if parent1 in gender and gender[parent1] == "male":
            gender[parent2] = "female"
            couple = (parent1, parent2)
        elif parent1 in gender:
            gender[parent2] = "male"
            couple = (parent2, parent1)
        elif parent2 in gender and gender[parent2] == "male":
            gender[parent1] = "female"
            couple = (parent2, parent1)
        else:
            gender[parent1] = "male"
            couple = (parent1, parent2)
        adj[couple] = []
        adj[parent1].append((couple, "spouse"))
        adj[parent2].append((couple, "spouse"))
        adj[couple].append((parent1, "spouse"))
        adj[couple].append((parent2, "spouse"))
        marriage[parent1] = couple
        marriage[parent2] = couple
        adj[child].append((couple, "parent"))
        adj[couple].append((child, "child"))
    q = int(sys.stdin.readline())
    for _ in range(q):
        name1, name2 = sys.stdin.readline().rstrip().split()
        queue = collections.deque()
        queue.append((name2, None, 0, 0, False))
        while queue:
            name, prev, p, c, in_law = queue.popleft()
            if name == name1:
                if p == 0 and c == 0:
                    if gender[name1] == "male":
                        relation = "husband"
                    else:
                        relation = "wife"
                    sys.stdout.write(f"{name1} is the {relation} of {name2}\n")
                elif p == 1 and c == 1:
                    if gender[name1] == "male":
                        relation = "brother"
                    else:
                        relation = "sister"
                    if in_law:
                        relation += "-in-law"
                    sys.stdout.write(f"{name1} is the {relation} of {name2}\n")
                elif p >= 2 and c >= 2:
                    degree = min(p, c) - 1
                    removal = abs(p - c)
                    if degree % 10 == 1 and degree != 11:
                        relation = f"{degree}st cousins"
                    elif degree % 10 == 2 and degree != 12:
                        relation = f"{degree}nd cousins"
                    elif degree % 10 == 3 and degree != 13:
                        relation = f"{degree}rd cousins"
                    else:
                        relation = f"{degree}th cousins"
                    if in_law:
                        relation += "-in-law"
                    if removal == 1:
                        relation += " 1-time removed"
                    elif removal >= 2:
                        relation += f" {removal}-times removed"
                    sys.stdout.write(f"{name1} and {name2} are {relation}\n")
                elif p >= 2 and c == 1:
                    relation = "great " * (p - 2)
                    if gender[name1] == "male":
                        relation += "uncle"
                    else:
                        relation += "aunt"
                    if in_law:
                        relation += "-in-law"
                    sys.stdout.write(f"{name1} is the {relation} of {name2}\n")
                elif p == 1 and c >= 2:
                    relation = "great " * (c - 2)
                    if gender[name1] == "male":
                        relation += "nephew"
                    else:
                        relation += "niece"
                    if in_law:
                        relation += "-in-law"
                    sys.stdout.write(f"{name1} is the {relation} of {name2}\n")
                elif c == 0:
                    relation = ""
                    if p >= 2:
                        relation += "great " * (p - 2) + "grand"
                    if gender[name1] == "male":
                        relation += "father"
                    else:
                        relation += "mother"
                    if in_law:
                        relation += "-in-law"
                    sys.stdout.write(f"{name1} is the {relation} of {name2}\n")
                else:
                    relation = ""
                    if c >= 2:
                        relation += "great " * (c - 2) + "grand"
                    if gender[name1] == "male":
                        relation += "son"
                    else:
                        relation += "daughter"
                    if in_law:
                        relation += "-in-law"
                    sys.stdout.write(f"{name1} is the {relation} of {name2}\n")
                break
            for name3, relation in adj[name]:
                p1, c1, in_law1 = p, c, in_law
                if name3 == prev:
                    continue
                if relation == "parent":
                    p1 += 1
                elif relation == "child":
                    c1 += 1
                elif name in [(prev, name3), (name3, prev)]:
                    in_law1 = True
                queue.append((name3, name, p1, c1, in_law1))


main()
