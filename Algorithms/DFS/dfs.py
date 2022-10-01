
"""
Input Graph
     1
    / \
   2   3

Output - 
1
2
3
"""

# Number of Nodes in the graph
N = 3

# Edges in graph
G = [[], [2, 3], [1], [1]]

def dfs(G, node, visited):

    print(node)

    for i in G[node]:
        if i not in visited:
            visited.add(i)
            dfs(G, i, visited)
    
dfs(G, 1, {1})
