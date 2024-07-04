import networkx as nx
import matplotlib.pyplot as plt

# Sample adjacency list
adjacency_list = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
    'C': ['A', 'D'],
    'D': ['B', 'C']
}

# Create a graph object
G = nx.Graph()

# Add edges from the adjacency list
for node, neighbors in adjacency_list.items():
    for neighbor in neighbors:
        G.add_edge(node, neighbor)

# Draw the graph
nx.draw(G, with_labels=True)
plt.show()