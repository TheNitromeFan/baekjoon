import sys


def main():
    while True:
        vertices, edges = set(), set()
        while True:
            try:
                line = sys.stdin.readline().rstrip()
            except (ValueError, EOFError):
                return
            if line == "GRAPH BEGIN":
                continue
            if line == "":
                return
            elif line == "GRAPH END":
                break
            nodes = line.split()
            u = nodes[0]
            vertices.add(u)
            for v in nodes[1:]:
                vertices.add(v)
                edges.add((u, v))
                edges.add((v, u))
        print(f"NODES {len(vertices)} EDGES {len(edges) // 2}")


main()
