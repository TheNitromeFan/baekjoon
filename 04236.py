import sys
import string


def main():
    while True:
        projects = {}
        students = {}
        current_project = ""
        while True:
            line = sys.stdin.readline().rstrip()
            if line == "0":
                return
            elif line == "1":
                break
            elif line.upper() == line:
                projects[line] = 0
                current_project = line
            else:
                if line in students and current_project in students[line]:
                    continue
                elif line in students:
                    students[line].add(current_project)
                    projects[current_project] += 1
                else:
                    students[line] = {current_project}
                    projects[current_project] += 1
        for student in students:
            if len(students[student]) > 1:
                for project in students[student]:
                    projects[project] -= 1
        project_signups = sorted(projects.items(), key=lambda x: (-x[1], x[0]))
        for project, signups in project_signups:
            sys.stdout.write("{} {}\n".format(project, signups))


main()
