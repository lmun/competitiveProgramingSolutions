import pygraphviz as pgv
from sys import stdin

G = pgv.AGraph()
for line in stdin:
    a, b, c = map(int, line.split())
    # G.add_node('a')
    # G.add_edge('b', 'c')
    G.add_edge(a, b, weight=c)
print(G)
G.layout(prog='dot')
G.draw('file.png')
