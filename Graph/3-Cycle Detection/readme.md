# Cycle Detection – DSA Pattern Series

## Category Overview
Cycle Detection problems focus on determining whether a graph contains a loop such that a node can be revisited by following edges.

This category is **fundamental** for:
- Graph validation
- Deadlock detection
- Dependency resolution
- Scheduling problems
- Network design

---

## First Decision Rule (Most Important)

Cycle detection strategy depends on:
- **Graph type**: Undirected / Directed
- **Edge behavior**: Static / Dynamic
- **Problem requirement**: Detection only or ordering required

---

## Total Standard Approaches

| # | Approach | Graph Type |
|--|--------|-----------|
| 1 | DFS + Parent Tracking | Undirected |
| 2 | BFS + Parent Tracking | Undirected |
| 3 | Union-Find (DSU) | Undirected |
| 4 | DFS + Recursion Stack | Directed |
| 5 | Kahn’s Algorithm (Topo Sort) | Directed |
| 6 | Graph Coloring (3-state DFS) | Directed |

---

## Approach 1: DFS + Parent Tracking (Undirected Graph)

### Core Idea
During DFS:
- If a visited neighbor is found
- And it is **not the parent**
→ A cycle exists

### Why It Works
Undirected edges are bidirectional. Parent tracking avoids false cycle detection.

### When to Use
- Static undirected graphs
- Adjacency list representation
- Simple implementation required

### Time & Space
- Time: O(V + E)
- Space: O(V)

### LeetCode Problems
- 261. Graph Valid Tree
- 1971. Find if Path Exists in Graph
- 684. Redundant Connection

---

## Approach 2: BFS + Parent Tracking (Undirected Graph)

### Core Idea
Same logic as DFS but implemented iteratively using a queue.

### When to Use
- Large graphs
- Avoid recursion stack overflow
- Competitive programming environments

### Time & Space
- Time: O(V + E)
- Space: O(V)

### LeetCode Problems
- 261. Graph Valid Tree
- 785. Is Graph Bipartite (variation)

---

## Approach 3: Union-Find (Disjoint Set Union)

### Core Idea
If an edge connects two vertices already in the same set, a cycle exists.

### Why It Works
A cycle implies multiple paths between nodes in the same component.

### When to Use
- Graph given as edge list
- Dynamic edge addition
- Kruskal’s MST
- Network connectivity problems

### Limitations
- Only works for **undirected graphs**
- Cannot detect direction-based cycles

### Time & Space
- Time: ~O(α(N))
- Space: O(N)

### LeetCode Problems
- 684. Redundant Connection
- 1319. Number of Operations to Make Network Connected
- 547. Number of Provinces

---

## Approach 4: DFS + Recursion Stack (Directed Graph)

### Core Idea
Track nodes currently in recursion stack.
If a node is revisited while still in stack → cycle exists.

### Why Parent Tracking Fails Here
Directed edges do not have symmetric back-edges.

### When to Use
- Directed graphs
- Dependency chains
- Course scheduling

### Time & Space
- Time: O(V + E)
- Space: O(V)

### LeetCode Problems
- 207. Course Schedule
- 802. Find Eventual Safe States
- 1059. All Paths from Source Lead to Destination

---

## Approach 5: Kahn’s Algorithm (Topological Sort)

### Core Idea
A Directed Acyclic Graph (DAG) must have a valid topological ordering.
If topo sort does **not** include all nodes → cycle exists.

### When to Use
- Directed graph
- Need ordering + cycle detection
- Scheduling problems

### Time & Space
- Time: O(V + E)
- Space: O(V)

### LeetCode Problems
- 207. Course Schedule
- 210. Course Schedule II
- 1136. Parallel Courses

---

## Approach 6: Graph Coloring (3-State DFS)

### Colors
- 0 → Unvisited
- 1 → Visiting (in recursion)
- 2 → Visited

### Core Idea
If during DFS you encounter a **Visiting (1)** node → cycle exists.

### When to Use
- Directed graphs
- Cleaner alternative to recursion stack
- Interview-friendly explanation

### Time & Space
- Time: O(V + E)
- Space: O(V)

### LeetCode Problems
- 207. Course Schedule
- 802. Find Eventual Safe States
- 2127. Maximum Employees to Be Invited to a Meeting

---

## Decision Table (Must Memorize)

| Graph Type | Best Approach |
|----------|---------------|
| Undirected | DFS / BFS Parent |
| Undirected (edge list) | Union-Find |
| Directed | DFS + Stack |
| Directed + Ordering | Kahn’s Algorithm |
| Directed (clean logic) | Coloring |

---

## Common Interview Mistakes

- Using Union-Find for directed graphs
- Using DFS for shortest path
- Forgetting recursion stack reset
- Confusing visited vs inStack
- Applying topo sort on undirected graph

---

## Pattern Recognition Keywords

If a problem mentions:
- “Loop”
- “Circular dependency”
- “Deadlock”
- “Not possible to finish”
- “Valid ordering”

→ **Think Cycle Detection**

---

## Learning Outcomes

After mastering this category, you will be able to:
- Instantly classify graph type
- Select correct cycle detection strategy
- Explain *why* a cycle exists
- Solve scheduling and dependency problems confidently

---

## Next Categories in Series

- Connected Components
- Bipartite Graph
- Topological Sorting (Deep Dive)
- Shortest Path Algorithms
- Minimum Spanning Tree

---

## One-Line Master Rule

**Undirected cycles → Parent / DSU**  
**Directed cycles → Stack / Topo**
