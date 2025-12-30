# Connected Components – DSA Pattern Series

## Category Overview
Connected Components problems focus on **identifying separate independent regions** in a graph or grid.

They answer questions like:
- How many disconnected parts exist?
- Are two nodes connected?
- What is the size of each region?
- Can we group elements into independent components?

This is one of the **most fundamental graph patterns** and appears frequently in:
- Graphs
- Grids (matrix problems)
- Union-Find based problems

---

## Core Pattern
> **Count / identify separate connected regions**

A **connected component** is:
- A group of nodes where **every node is reachable from any other node in the group**

---

## First Decision Rule (MOST IMPORTANT)

> **If the problem asks “how many groups / islands / provinces / components?” → think Connected Components**

---

## Graph Types & Meaning of Connectivity

| Structure | Connectivity Meaning |
|--------|----------------------|
| Undirected Graph | Mutual reachability |
| Directed Graph | Weak / Strong connectivity |
| Grid | Adjacent cells (4 or 8 direction) |

---

## How Many Ways to Solve Connected Components?

### ✅ **3 Primary Approaches**

| # | Method | Core Idea |
|--|------|----------|
| 1 | DFS | Explore entire region recursively |
| 2 | BFS | Explore region level by level |
| 3 | Union-Find (DSU) | Merge connected nodes |

---

## Approach 1: DFS (Depth First Search)

### Core Idea
- Start from an unvisited node
- Explore **all reachable nodes**
- Mark them visited
- Each DFS call = **1 component**

---

### Algorithm Steps
1. Maintain visited array / modify grid
2. Loop through all nodes
3. If node unvisited → DFS
4. Increment component count

---

### When to Use
- Counting components
- Flood fill
- Island problems
- Grid traversal

---

### Time & Space
- Time: O(V + E) or O(m × n)
- Space: O(V) recursion stack

---

### LeetCode Problems
- 200. Number of Islands
- 547. Number of Provinces
- 695. Max Area of Island
- 1254. Number of Closed Islands

---

### Key Insight
> **One DFS traversal completely consumes one component**

---

## Approach 2: BFS (Breadth First Search)

### Core Idea
- Same logic as DFS
- Uses queue instead of recursion
- Better for large grids (avoids stack overflow)

---

### Algorithm Steps
1. Loop through nodes
2. If unvisited → BFS
3. Push neighbors into queue
4. Mark visited

---

### When to Use
- Large graphs
- Avoid recursion limits
- When level-wise traversal helps

---

### Time & Space
- Time: O(V + E)
- Space: O(V)

---

### LeetCode Problems
- 200. Number of Islands
- 994. Rotting Oranges (component + BFS)
- 733. Flood Fill

---

### DFS vs BFS (Components)

| Aspect | DFS | BFS |
|----|----|----|
| Implementation | Recursive | Iterative |
| Stack overflow risk | Yes | No |
| Preferred for grids | Yes | Yes |

---

## Approach 3: Union-Find (Disjoint Set Union)

### Core Idea
- Each node starts as its own component
- Union connected nodes
- Final parent count = components

---

### Algorithm Steps
1. Initialize parent array
2. For each edge / adjacency → union
3. Count unique parents

---

### When to Use
- Dynamic connectivity
- Offline queries
- Graph given as edge list

---

### Time & Space
- Time: ~O(α(n)) per operation
- Space: O(n)

---

### LeetCode Problems
- 547. Number of Provinces
- 721. Accounts Merge
- 323. Number of Connected Components

---

### Key Insight
> **Union-Find is best when edges arrive dynamically**

---

## Grid-Specific Connected Components

### Direction Types

| Direction | Moves |
|--------|------|
| 4-direction | Up, Down, Left, Right |
| 8-direction | Includes diagonals |

---

### 8-Direction Movement (Very Important)

```cpp
int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {-1,0,1,-1,1,-1,0,1};
for(int dir = 0; dir < 8; dir++) {
    int newX = x + dx[dir];
    int newY = y + dy[dir];
    // Check bounds and process (newX, newY)
}
```
---