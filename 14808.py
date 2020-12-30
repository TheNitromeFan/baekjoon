import sys


def solve_for_one_route(horses, adj, u, v, speed=0, max_total_dist=0, already_reached=[]):
    if u == v:
        return 0
    e, s = horses[u]
    neighbors = adj[u]
    spent_time_list = []
    for i, dist in enumerate(neighbors):
        if dist == -1 or i in already_reached:
            continue
        arr = already_reached[::]
        arr.append(i)
        if dist <= max_total_dist and not (max_total_dist < e and speed < s):
            extra_time = solve_for_one_route(horses, adj, i, v, speed, max_total_dist - dist, arr)
            if extra_time is not None:
                spent_time_list.append(dist / speed + extra_time)
        if dist <= e and not (e < max_total_dist and s < speed):
            extra_time = solve_for_one_route(horses, adj, i, v, s, e - dist, arr)
            if extra_time is not None:
                spent_time_list.append(dist / s + extra_time)
    if not spent_time_list:
        return None
    return min(spent_time_list)


def main():
    t = int(sys.stdin.readline())
    for a0 in range(1, t + 1):
        n, q = (int(x) for x in sys.stdin.readline().split())
        horses = []
        for _ in range(n):
            e, s = (int(x) for x in sys.stdin.readline().split())
            horses.append((e, s))
        adj = []
        for _ in range(n):
            adj.append([int(x) for x in sys.stdin.readline().split()])
        routes = []
        sys.stdout.write(f"Case #{a0}:")
        for _ in range(q):
            u, v = (int(x) for x in sys.stdin.readline().split())
            sys.stdout.write(f" {solve_for_one_route(horses, adj, u - 1, v - 1)}")
        sys.stdout.write("\n")


main()
