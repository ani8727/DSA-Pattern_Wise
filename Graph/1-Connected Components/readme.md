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

| Structure        | Connectivity Meaning      |
|------------------|---------------------------|
| Undirected Graph | Mutual reachability       |
| Directed Graph   | Weak / Strong connectivity |
| Grid             | Adjacent cells (4 or 8 direction) |

---

## How Many Ways to Solve Connected Components?

### ✅ **3 Primary Approaches**

| #   | Method       | Core Idea                          |
|-----|--------------|------------------------------------|
| 1   | DFS          | Explore entire region recursively |
| 2   | BFS          | Explore region level by level     |
| 3   | Union-Find   | Merge connected nodes             |

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

| Aspect            | DFS        | BFS        |
|-------------------|------------|------------|
| Implementation    | Recursive  | Iterative  |
| Stack overflow risk | Yes        | No         |
| Preferred for grids | Yes        | Yes        |

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

| Direction    | Moves                        |
|--------------|------------------------------|
| 4-direction  | Up, Down, Left, Right        |
| 8-direction  | Includes diagonals           |

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

## Practice Problems

### Connected Components (5 Problems)

1. **[Number of Provinces (LC 547)](https://leetcode.com/problems/number-of-provinces/)**  
   ⭐ Start here
2. **[Number of Islands (LC 200)](https://leetcode.com/problems/number-of-islands/)**  
   ⭐ Grid DFS
3. **[Max Area of Island (LC 695)](https://leetcode.com/problems/max-area-of-island/)**
4. **[Flood Fill (LC 733)](https://leetcode.com/problems/flood-fill/)**
5. **[Island Perimeter (LC 463)](https://leetcode.com/problems/island-perimeter/)**

---

### Basic Traversal (5 Problems)

6. **[All Paths from Source to Target (LC 797)](https://leetcode.com/problems/all-paths-from-source-to-target/)**  
   ⭐ DFS Backtracking
7. **[Find if Path Exists (LC 1971)](https://leetcode.com/problems/find-if-path-exists-in-graph/)**
8. **[Clone Graph (LC 133)](https://leetcode.com/problems/clone-graph/)**  
   ⭐ DFS/BFS
9. **[Keys and Rooms (LC 841)](https://leetcode.com/problems/keys-and-rooms/)**
10. **[Find Center of Star Graph (LC 1791)](https://leetcode.com/problems/find-center-of-star-graph/)**

---

### Advanced Problems (5 Problems)

11. **[Accounts Merge (LC 721)](https://leetcode.com/problems/accounts-merge/)**  
    ⭐ Union-Find
12. **[Number of Connected Components in an Undirected Graph (LC 323)](https://leetcode.com/problems/number-of-connected-components-in-an-undirected-graph/)**
13. **[Redundant Connection (LC 684)](https://leetcode.com/problems/redundant-connection/)**  
    ⭐ Union-Find
14. **[Critical Connections in a Network (LC 1192)](https://leetcode.com/problems/critical-connections-in-a-network/)**  
    ⭐ Tarjan’s Algorithm
15. **[Bricks Falling When Hit (LC 803)](https://leetcode.com/problems/bricks-falling-when-hit/)**  
    ⭐ Union-Find/Grid DFS

---

### Grid-Specific Problems (5 Problems)

16. **[Rotting Oranges (LC 994)](https://leetcode.com/problems/rotting-oranges/)**  
    ⭐ BFS
17. **[Surrounded Regions (LC 130)](https://leetcode.com/problems/surrounded-regions/)**  
    ⭐ DFS/BFS
18. **[Walls and Gates (LC 286)](https://leetcode.com/problems/walls-and-gates/)**  
    ⭐ BFS
19. **[Word Search (LC 79)](https://leetcode.com/problems/word-search/)**  
    ⭐ Backtracking
20. **[Word Search II (LC 212)](https://leetcode.com/problems/word-search-ii/)**  
    ⭐ Trie + Backtracking