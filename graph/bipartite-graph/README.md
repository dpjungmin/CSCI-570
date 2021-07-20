| Problem                                                                  |         Code          | Algorithm |
| ------------------------------------------------------------------------ | :-------------------: | :-------: |
| [Is Graph Bipartite?](https://leetcode.com/problems/is-graph-bipartite/) | [C++20](solution.cpp) | BFS & DFS |

## Algorithm Design

Run **BFS** starting from any node. Label each node **RED** or **BLUE** depending on whether they appear at an odd or even level on the **BFS tree** (we must consider that the graph may not be a connected graph).

Then, go through all edges and examine the labels at the two ends of the edge. If all edges have a\* **RED** end and a **BLUE** end, then the graph is bipartite.

You could also do a **DFS** to solve this problem.

## Complexity Analysis

Let `|V| = n` and `|E| = m`. Constructing the **BFS** tree would take `O(n + m)` and going through all edges would take `O(m)`. In the implementation, we could combine these steps and check each edge while constructing the **BFS tree**. If we find an edge with the same color on each side, stop!

Thus, the overall time complexity would be `O(m + n)` and space complexity would be `O(n)`.
