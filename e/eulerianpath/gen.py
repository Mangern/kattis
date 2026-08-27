import networkx as nx
from subprocess import Popen
import os
import random

def make_eulerian_directed(G):
    """Modify a directed graph to ensure in-degree equals out-degree (Eulerian circuit)."""
    hit = True
    while hit:
        hit = False
        for node in G.nodes:
            in_deg = G.in_degree(node)
            out_deg = G.out_degree(node)

            if in_deg == out_deg:
                continue

            hit = True
            
            # If out-degree > in-degree, add incoming edges
            while out_deg > in_deg:
                target = random.choice(list(G.nodes))
                if target != node:
                    G.add_edge(target, node)
                in_deg += 1

            # If in-degree > out-degree, add outgoing edges
            while in_deg > out_deg:
                target = random.choice(list(G.nodes))
                if target != node:
                    G.add_edge(node, target)
                out_deg += 1

    if random.randint(1, 2) == 2:
        G.add_edge(0, random.choice([n for n in G.nodes if n != 0]))

def test():
    n = 20
    G = None
    m = 0
    euler = random.randint(1,4)!=2
    while G is None or m == 0:
        G = nx.gn_graph(n)
        if euler:
            make_eulerian_directed(G)
        m = len(list(G.edges()))

    with open("tmp.in", "w") as f:
        f.write(f"{n} {m}\n")
        for u,v in G.edges():
            f.write(f"{u} {v}\n")
        f.write(f"{0} {0}")
    p = Popen("./a.out < tmp.in > tmp.out", shell=True)
    try:
        p.wait(timeout=5.0)
    except:
        print("Killed")
        p.kill()
        exit(1)
    path = open("tmp.out").read().strip()
    if path == "Impossible" and euler:
        print("Impossible. Impossible is impossible")
        exit(1)
    elif path == "Impossible" and not euler:
        print("Prob ok")
    else:
        path = list(map(int, path.split()))
        if len(path) != m + 1:
            print("WRONG LENGTH!")
            exit(1)
        edgeset = {(u,v) for u,v in G.edges()}
        for u, v in zip(path, path[1:]):
            if (u, v) not in edgeset:
                print("FAIL! Bad edge")
                exit(1)
            edgeset.remove((u,v))

        if len(edgeset):
            print("FAIL! Missing edge")
            exit(1)
        print("ok")

    os.system("rm tmp*")

for i in range(50000):
    test()
