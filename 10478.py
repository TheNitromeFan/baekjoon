import sys


def floyd_warshall(adj, vertices):
    for vertex1 in vertices:
        for vertex2 in vertices:
            for vertex3 in vertices:
                if (vertex2, vertex3) not in adj and (vertex2, vertex1) in adj and (vertex1, vertex3) in adj:
                    a, b = adj[(vertex2, vertex1)]
                    c, d = adj[(vertex1, vertex3)]
                    ac, bd = a * c, b * d
                    if bd % ac == 0:
                        adj[(vertex2, vertex3)] = (1, bd // ac)
                        adj[(vertex3, vertex2)] = (bd // ac, 1)
                    else:
                        adj[(vertex2, vertex3)] = (ac // bd, 1)
                        adj[(vertex3, vertex2)] = (1, ac // bd)
    return adj


def source_vertex(adj, vertices):
    for vertex in vertices:
        if all(adj[(vertex, vertex1)][0] == 1 for vertex1 in vertices):
            return vertex


def main():
    while True:
        n = int(sys.stdin.readline())
        if n == 0:
            break
        vertices = sys.stdin.readline().split()
        adj = {(vertex, vertex): (1, 1) for vertex in vertices}
        for _ in range(n - 1):
            entries = sys.stdin.readline().rstrip().split()
            adj[(entries[0], entries[3])] = (1, int(entries[2]))
            adj[(entries[3], entries[0])] = (int(entries[2]), 1)
        adj = floyd_warshall(adj, vertices)
        src = source_vertex(adj, vertices)
        vertices.sort(key=lambda x: adj[(src, x)])
        print(" = ".join("{}{}".format(adj[(src, vertex)][1], vertex) for vertex in vertices))


main()
