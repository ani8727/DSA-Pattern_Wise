# Shortest Path – DSA Pattern Series

## Category Overview
Shortest Path problems focus on finding the **minimum cost / minimum distance / minimum steps** required to travel from a source node to one or more destination nodes.

These problems appear in:
- Navigation systems
- Network routing
- Task pipelines
- Game grids
- Dependency graphs

---

## Core Question This Category Solves

- What is the minimum distance from source to destination?
- Can we reach the destination within constraints?
- What is the cheapest / fastest path?
- How does distance propagate through a system?

---

## First Decision Rule (MOST IMPORTANT)

> **Shortest Path strategy depends on edge weights**

| Edge Type | Algorithm |
|---------|----------|
| No weights (unweighted) | BFS |
| Weights = 0 or 1 | 0–1 BFS |
| Non-negative weights | Dijkstra |
| Negative weights | Bellman–Ford |
| DAG | Topological DP |
| All-pairs | Floyd–Warshall |

---

## How Many Ways to Solve Shortest Path?

### ✅ **6 Standard Approaches**

| # | Approach | Graph Type |
|--|--------|-----------|
| 1 | BFS | Unweighted |
| 2 | 0–1 BFS | Weights {0,1} |
| 3 | Dijkstra | Non-negative |
| 4 | Bellman–Ford | Negative edges |
| 5 | DAG Shortest Path | Directed Acyclic |
| 6 | Floyd–Warshall | All-pairs |

---

## Approach 1: BFS (Unweighted Shortest Path)

### Core Idea
In an unweighted graph:
- Each edge has equal cost
- BFS explores nodes level by level
- First visit = shortest path

---

### When to Use
- Grid problems
- Binary matrix
- Minimum steps
- No edge weights

---

### Time & Space
- Time: O(V + E)
- Space: O(V)

---

### LeetCode Problems
- 1091. Shortest Path in Binary Matrix
- 127. Word Ladder
- 542. 01 Matrix
- 994. Rotting Oranges

---

### Key Trick
> **BFS level = distance**

---

## Approach 2: 0–1 BFS

### Core Idea
- Edge weights are only **0 or 1**
- Use **deque instead of queue**
- Push front for 0-cost edges
- Push back for 1-cost edges

---

### When to Use
- Binary weight graphs
- Faster than Dijkstra
- Memory efficient

---

### Time & Space
- Time: O(V + E)
- Space: O(V)

---

### LeetCode / GFG Problems
- 1368. Minimum Cost to Make at Least One Valid Path
- GFG: Minimum Cost Path (0–1 BFS version)

---

### Key Trick
> Avoid priority queue when weights are 0/1

---

## Approach 3: Dijkstra’s Algorithm

### Core Idea
- Greedy algorithm
- Always expand the **closest unvisited node**
- Uses priority queue (min-heap)

---

### When to Use
- Non-negative edge weights
- Weighted graphs
- Most real-world shortest path problems

---

### Time & Space
- Time: O(E log V)
- Space: O(V)

---

### LeetCode Problems
- 743. Network Delay Time
- 1631. Path With Minimum Effort
- 787. Cheapest Flights Within K Stops
- 1514. Path with Maximum Probability

---

### Important Insight
> **Dijkstra fails with negative edges**

---

## Approach 4: Bellman–Ford Algorithm

### Core Idea
- Relax all edges **V−1 times**
- Can detect negative cycles

---

### When to Use
- Negative edge weights
- Need cycle detection
- Graph size is small/moderate

---

### Time & Space
- Time: O(V × E)
- Space: O(V)

---

### LeetCode Problems
- 787. Cheapest Flights Within K Stops (DP/Bellman variation)
- GFG: Detect Negative Cycle

---

### Key Trick
> Use Bellman–Ford when **Dijkstra is invalid**

---

## Approach 5: Shortest Path in DAG (Topo + DP)

### Core Idea
- DAG has no cycles
- Process nodes in topological order
- Relax edges once

---

### When to Use
- Directed Acyclic Graph
- Dependency-based cost propagation
- Faster than Dijkstra

---

### Time & Space
- Time: O(V + E)
- Space: O(V)

---

### LeetCode / GFG Problems
- 329. Longest Increasing Path (reverse thinking)
- GFG: Shortest Path in DAG

---

### Key Insight
> **No cycles → no reprocessing → linear time**

---

## Approach 6: Floyd–Warshall (All-Pairs Shortest Path)

### Core Idea
- Dynamic Programming
- Try all intermediate nodes
- Computes distance between **every pair**

---

### When to Use
- Small graphs
- Multiple queries
- All-pairs distances

---

### Time & Space
- Time: O(V³)
- Space: O(V²)

---

### LeetCode Problems
- 1334. Find the City With the Smallest Number of Neighbors
- GFG: Floyd Warshall Algorithm

---

## Comparison of All Approaches (VERY IMPORTANT)

| Feature | BFS | 0–1 BFS | Dijkstra | Bellman | DAG | Floyd |
|------|----|--------|---------|--------|-----|------|
| Weighted | ❌ | {0,1} | ✅ | ✅ | ✅ | ✅ |
| Negative edges | ❌ | ❌ | ❌ | ✅ | ❌ | ❌ |
| Cycle handling | ✅ | ✅ | ✅ | ✅ | ❌ | ❌ |
| All-pairs | ❌ | ❌ | ❌ | ❌ | ❌ | ✅ |
| Fastest | ✅ | ✅ | ⚡ | ❌ | ⚡ | ❌ |

---

## Interview Decision Guide

1. **Unweighted graph?** → BFS  
2. **0/1 weights?** → 0–1 BFS  
3. **Non-negative weights?** → Dijkstra  
4. **Negative edges?** → Bellman–Ford  
5. **DAG?** → Topo + DP  
6. **All-pairs?** → Floyd–Warshall  

---

## Common Interview Traps

- Using DFS for shortest path
- Using Dijkstra with negative edges
- Forgetting K-stop constraint
- Confusing BFS level with weight

---

## Advanced Insights & Tricks

### K-Stops Constraint
- Use BFS with depth limit
- Or Bellman–Ford with limited relaxations

### Signal Propagation
- Distance spreads like waves
- BFS/Dijkstra simulate propagation

### Grid Problems
- Use direction arrays
- Mark visited early
- BFS preferred

---

## Pattern Recognition Keywords

If problem mentions:
- Minimum distance
- Minimum cost
- Shortest time
- Cheapest path
- Fewest steps

→ **Think Shortest Path**

---

## Learning Outcomes

After mastering this category, you will:
- Instantly choose the correct algorithm
- Handle constraints confidently
- Avoid common mistakes
- Solve both graph and grid problems

---

## Next Categories

- Minimum Spanning Tree
- Strongly Connected Components
- Advanced Graph DP
- Flow Algorithms

---

## One-Line Master Rule

> **Shortest Path = Correct algorithm based on edge weight**
