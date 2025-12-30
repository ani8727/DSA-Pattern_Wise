# Topological Ordering – DSA Pattern Series

## Category Overview
Topological Ordering problems deal with **ordering tasks that have dependencies**.

They answer questions like:
- In what order should tasks be executed?
- Is it possible to finish all tasks?
- Does a cycle exist in dependencies?
- Can we derive a valid ordering?

Topological Sort applies **only to Directed Acyclic Graphs (DAGs)**.

---

## Core Pattern
> **Order tasks with dependencies**

If task `A → B`, then:
- `A` must come **before** `B`

---

## First Decision Rule (MOST IMPORTANT)

> **If dependencies form a cycle → Topological order is impossible**

| Graph Type | Topo Sort Possible |
|----------|------------------|
| Directed + Acyclic | ✅ |
| Directed + Cyclic | ❌ |
| Undirected | ❌ |

---

## How Many Ways to Solve Topological Ordering?

### ✅ **2 Primary Algorithms**

| # | Method | Core Idea |
|--|------|----------|
| 1 | Kahn’s Algorithm | BFS + Indegree |
| 2 | DFS Based | Postorder stack |

Both produce valid topological orders, but **use cases differ**.

---

## Approach 1: Kahn’s Algorithm (BFS Based)

### Core Idea
- Count **indegree** (incoming edges) of each node
- Nodes with indegree `0` have no dependencies
- Process them first
- Remove edges and update indegrees

---

### Algorithm Steps
1. Build graph
2. Compute indegree of each node
3. Push all `indegree = 0` nodes into queue
4. Pop → process → reduce neighbors’ indegree
5. Add new `0 indegree` nodes to queue

---

### When to Use
- Need **explicit ordering**
- Need **cycle detection**
- Preferred in interviews
- Works well for course / task scheduling

---

### Time & Space
- Time: O(V + E)
- Space: O(V)

---

### LeetCode Problems
- 207. Course Schedule
- 210. Course Schedule II
- 802. Find Eventual Safe States
- 1136. Parallel Courses

---

### Key Insight
> **If processed nodes < V → cycle exists**

---

## Approach 2: DFS Based Topological Sort

### Core Idea
- Perform DFS
- Add node to stack **after visiting all neighbors**
- Reverse stack gives topological order

---

### Algorithm Steps
1. Run DFS on all nodes
2. Mark visited
3. After DFS finishes for node → push to stack
4. Reverse stack for answer

---

### When to Use
- Graph traversal problems
- When DFS already exists
- Used in SCC / Kosaraju pipeline

---

### Time & Space
- Time: O(V + E)
- Space: O(V)

---

### LeetCode / GFG Problems
- GFG: Topological Sort (DFS)
- Used internally in SCC problems

---

### Limitation
> **DFS topo does NOT directly detect cycles**  
(extra recursion stack check needed)

---

## Comparison: Kahn vs DFS

| Feature | Kahn (BFS) | DFS |
|------|-----------|-----|
| Cycle detection | ✅ Easy | ⚠️ Extra logic |
| Ordering clarity | ✅ Explicit | ❌ Indirect |
| Interview friendly | ⭐⭐⭐⭐ | ⭐⭐⭐ |
| Memory | Queue | Stack |
| Practical use | Scheduling | Graph analysis |

---

## Special Topological Patterns

### 1. Course Scheduling Pattern
- Tasks = courses
- Edges = prerequisites
- Ask:
  - Can all tasks be done?
  - Give valid order

**Problems**
- LC 207
- LC 210

---

### 2. Alien Dictionary Pattern

#### Core Idea
- Characters are nodes
- Compare adjacent words
- First mismatching character defines order

---

#### Steps
1. Build graph from word list
2. Topological sort characters
3. Detect invalid prefix case

---

#### LeetCode Problem
- 269. Alien Dictionary

---

### 3. Parallel Tasks / Levels Pattern

#### Core Idea
- Each BFS layer = parallel execution
- Count number of layers

---

#### Problems
- 1136. Parallel Courses
- 2050. Parallel Courses III

---

### Key Insight
> **BFS level = minimum semesters**

---

### 4. Eventual Safe States

#### Core Idea
- Reverse graph
- Nodes with outdegree = 0 are safe
- Apply Kahn’s logic on reversed graph

---

#### Problem
- 802. Find Eventual Safe States

---

## Cycle Detection Using Topological Sort

### Using Kahn’s Algorithm
- If result size < number of nodes → cycle

### Using DFS
- Maintain recursion stack
- Back-edge = cycle

---

## Common Interview Traps

- Applying topo sort on undirected graph
- Forgetting prefix invalid case (Alien Dictionary)
- Assuming single valid order (multiple exist)
- Confusing BFS topo with shortest path

---

## Pattern Recognition Keywords

If problem mentions:
- Prerequisites
- Dependencies
- Ordering tasks
- Compile order
- Course sequence

→ **Think Topological Sort**

---

## One-Line Master Rule

> **Topological Sort = Ordering nodes such that all dependencies are respected**

---

## Learning Outcomes

After mastering this category, you will:
- Instantly detect DAG problems
- Choose correct topo approach
- Handle cycles confidently
- Solve scheduling & dependency questions

---

## Next Categories

- Shortest Path Algorithms
- Minimum Spanning Tree
- Strongly Connected Components
- Graph DP

---

## Final Interview Tip

> **If ordering + dependency exists → always try Topological Sort first** 
