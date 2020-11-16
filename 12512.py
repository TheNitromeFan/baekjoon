import sys


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        entries = sys.stdin.readline().rstrip().split()
        ind = 0
        c = int(entries[ind])
        ind += 1
        combine = {}
        for _ in range(c):
            s = entries[ind]
            combine[s[0] + s[1]] = s[2]
            combine[s[1] + s[0]] = s[2]
            ind += 1
        d = int(entries[ind])
        ind += 1
        destroy = set()
        for _ in range(d):
            s = entries[ind]
            destroy.add(s)
            destroy.add(s[::-1])
            ind += 1
        ind += 1
        invoke = entries[ind]
        elements = []
        # print(combine, destroy, invoke)
        for element in invoke:
            if not elements:
                elements.append(element)
                # print(elements)
                continue
            prev = elements[-1]
            if prev + element in combine:
                elements.pop()
                elements.append(combine[prev + element])
                # print(elements)
                continue
            destroy_flag = False
            for element1 in elements:
                if element + element1 in destroy:
                    elements = []
                    # print(elements)
                    destroy_flag = True
                    break
            if destroy_flag:
                continue
            elements.append(element)
            # print(elements)
        print("Case #{}: [{}]".format(a0, ", ".join(elements)))


main()
